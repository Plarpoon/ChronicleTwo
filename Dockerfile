FROM --platform=linux/amd64 debian:trixie-slim AS base

# Tool versions
ARG BINUTILS_VERSION=v0.10
ARG CLANGD_VERSION=22.1.6
ARG OBJDIFF_VERSION=v3.7.3

# Env vars
ENV DEBIAN_FRONTEND=noninteractive
ENV BINUTILS /usr/local/binutils-mips-ps2-decompals
ENV VIRTUAL_ENV /opt/venv
ENV PATH $PATH:${BINUTILS}:${VIRTUAL_ENV}/bin

# Base requirements
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        apt-transport-https \
        ca-certificates \
        git \
        gnupg \
        gpg-agent \
        sudo \
        unzip \
        wget \
        python3 \
        python3-venv \
        cmake \
        ninja-build \
        gdb \
    && rm -rf /var/lib/apt/lists/* 

# Acquire and move binutils to the correct location
RUN wget -O /tmp/binutils.tar.gz \
        https://github.com/decompals/binutils-mips-ps2-decompals/releases/download/${BINUTILS_VERSION}/binutils-mips-ps2-decompals-linux-x86-64.tar.gz \
    && mkdir -p ${BINUTILS} \
    && tar xzf /tmp/binutils.tar.gz -C ${BINUTILS} \
    && rm /tmp/binutils.tar.gz

# wibo is used to run MWCC
COPY --from=ghcr.io/decompals/wibo:latest /usr/local/bin/wibo /usr/bin/

# Install pip packages
RUN python3 -m venv $VIRTUAL_ENV
RUN python -m pip install pycdlib "splat64[mips]==0.50.0" libclang

#
# Development stage
#

FROM base AS dev

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        less \
        build-essential \
        doxygen \
        unzip \
    && rm -rf /var/lib/apt/lists/*

RUN wget -O /tmp/clangd.zip \
        https://github.com/clangd/clangd/releases/download/${CLANGD_VERSION}/clangd-linux-${CLANGD_VERSION}.zip \
    && unzip -q /tmp/clangd.zip -d /opt \
    && ln -s /opt/clangd_${CLANGD_VERSION}/bin/clangd /usr/local/bin/clangd \
    && ln -s /opt/clangd_${CLANGD_VERSION}/bin/clangd /usr/bin/clangd \
    && rm /tmp/clangd.zip

RUN wget -O /usr/local/bin/objdiff-cli \
        https://github.com/encounter/objdiff/releases/download/${OBJDIFF_VERSION}/objdiff-cli-linux-x86_64 \
    && chmod +x /usr/local/bin/objdiff-cli

# Required by decomp permuter
RUN python -m pip install toml levenshtein

#
# Build stage
#
FROM base AS build

WORKDIR /chronicletwo

COPY . .
