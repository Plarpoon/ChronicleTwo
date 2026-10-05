#include "common.h"
#include "scriptinterpreter.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

// The inline members of the header are called here, never expanded.
#pragma dont_inline on

static void PreProcess(input_str &in);
#ifdef NONMATCHING
static int SkipSpace(input_str &in);
static int CheckChar(char c);
#endif

// Code (.text)
int input_str::GetLine(char *line, int line_size, char *terminator) {
    char crlf[] = "\r\n";
    int  length;
    int  count;
    int  found;
    int  c;

    if (terminator == NULL) {
        terminator = crlf;
    }
    length = strlen(terminator);
    count = 0;
    found = 1;
    for (;;) {
        if (memcmp(&buffer[position], terminator, length) == 0) {
            position += length;
            break;
        }
        if (!get(&c)) {
            found = 0;
            break;
        }
        if (count < line_size - 1) {
            line[count++] = c;
        }
    }
    line[count] = '\0';
    return found;
}

int spiGetStackInt(SPI_STACK *stack) {
    switch (stack->type) {
    case SPI_STACK_TYPE_INT:
        return stack->value.integer;
    case SPI_STACK_TYPE_FLOAT:
        return (int)stack->value.real;
    default:
        return 0;
    }
}

float spiGetStackFloat(SPI_STACK *stack) {
    switch (stack->type) {
    case SPI_STACK_TYPE_INT:
        return (float)stack->value.integer;
    case SPI_STACK_TYPE_FLOAT:
        return stack->value.real;
    default:
        return 0.0f;
    }
}

char *spiGetStackString(SPI_STACK *stack) {
    switch (stack->type) {
    case SPI_STACK_TYPE_STRING:
        return stack->value.string;
    default:
        return NULL;
    }
}

void spiGetStackVector(float *vector, SPI_STACK *stack) {
    vector[0] = spiGetStackFloat(stack++);
    vector[1] = spiGetStackFloat(stack++);
    vector[2] = spiGetStackFloat(stack++);
}

#ifdef NONMATCHING
void CScriptInterpreter::PushStack(SPI_STACK argument) {
    if (stack_count < stack_size) {
        stack[stack_count] = argument;
        stack_count++;
    } else {
        printf("SPI stack over!!\n");
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", PushStack__18CScriptInterpreterF9SPI_STACK);
#endif
#ifdef NONMATCHING
// Defined in scriptinterpreter.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", __as__9SPI_STACKFRC9SPI_STACK);
#endif
#ifdef NONMATCHING
int CScriptInterpreter::GetNextTAG(int call) {
    char string_storage[SPI_STRING_BUFF_SIZE];
    SPI_STACK arguments[SPI_STACK_SIZE];
    int index;
    int c;
    int argument_count;

    if (tag == NULL) {
        return -1;
    }
    SetStringBuff(string_storage, SPI_STRING_BUFF_SIZE);
    for (;;) {
        SetStack(arguments, SPI_STACK_SIZE);
        if (!SearchCommand(&index)) {
            return -1;
        }
        if (binary) {
            argument_count = GetArgBin();
            if (index < tag_count && index >= 0 && call && tag[index].function != NULL) {
                tag[index].function(stack, argument_count);
            }
            return index;
        }
        if (index < tag_count && index >= 0) {
            argument_count = GetArg();
            if (call && tag[index].function != NULL) {
                tag[index].function(stack, argument_count);
            }
            return index;
        }
        // An unknown tag is passed over up to its semicolon.
        while (get(&c) && c != ';') {
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", GetNextTAG__18CScriptInterpreterFi);
#endif
#ifdef NONMATCHING
// Defined in scriptinterpreter.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SetStack__18CScriptInterpreterFP9SPI_STACKi);
#endif
#ifdef NONMATCHING
// Defined in scriptinterpreter.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SetStringBuff__18CScriptInterpreterFPci);
#endif

void CScriptInterpreter::Run() {
    while (GetNextTAG(1) >= 0) {
    }
}

int CScriptInterpreter::hash(char *name) {
    u8 value = 0;

    while (*name != '\0') {
        value = ((value << 8) + *name++) % SPI_HASH_BUCKET_COUNT;
    }
    return value;
}

#ifdef NONMATCHING
void CScriptInterpreter::SetTag(SPI_TAG_PARAM *tags) {
    SPI_TAG_PARAM *param;
    SPI_TAG_HASH *entry;
    SPI_TAG_HASH **chain;
    SPI_TAG_HASH *link;
    int i;

    tag = tags;
    tag_count = 0;
    for (param = tag; param->name != NULL && param->name[0] != '\0'; param++) {
        tag_count++;
    }

    hash_table = NULL;
    if (tag_count < SPI_HASH_TAG_MAX) {
        hash_table = hash_buckets;
        for (i = 0; i < SPI_HASH_BUCKET_COUNT; i++) {
            hash_table[i] = NULL;
        }

        entry = hash_entries;
        param = tag;
        for (i = 0; i < tag_count; i++) {
            entry->next = NULL;
            entry->name = param->name;
            entry->index = i;

            // Each entry is appended at the tail of its chain.
            chain = &hash_table[hash(param->name)];
            if (*chain == NULL) {
                *chain = entry;
            } else {
                for (link = *chain; link != NULL; link = link->next) {
                    if (link->next == NULL) {
                        link->next = entry;
                        break;
                    }
                }
            }
            entry++;
            param++;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SetTag__18CScriptInterpreterFP13SPI_TAG_PARAM);
#endif

void CScriptInterpreter::SetScript(char *script, int script_size) {
    buffer = script;
    size = script_size;
    position = 0;
    stack_count = 0;
    binary = 0;
    if (strncmp(script, "BIN", 3) == 0) {
        binary = 1;
        // The "BIN" header and its terminator.
        position += 4;
    } else {
        PreProcess(*this);
    }
}

#ifdef NONMATCHING
CScriptInterpreter::CScriptInterpreter() {
    buffer = NULL;
    size = 0;
    position = 0;
    stack_count = 0;
    stack = NULL;
    tag = NULL;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", __ct__18CScriptInterpreterFv);
#endif
#ifdef NONMATCHING
// Defined in scriptinterpreter.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", __ct__9input_strFv);
#endif
#ifdef NONMATCHING
int CScriptInterpreter::GetArgBin() {
    s8 types[SPI_TOKEN_SIZE];
    SPI_STACK argument;
    int count;
    int i;
    int padding;
    int length;

    count = *(s16 *)&buffer[position];
    position += 2;
    if (count == 0) {
        return 0;
    }

    for (i = 0; i < count; i++) {
        switch (buffer[position++]) {
        case SPI_BINARY_ARG_TYPE_STRING:
            types[i] = SPI_STACK_TYPE_STRING;
            break;
        case SPI_BINARY_ARG_TYPE_FLOAT:
            types[i] = SPI_STACK_TYPE_FLOAT;
            break;
        case SPI_BINARY_ARG_TYPE_INT:
            types[i] = SPI_STACK_TYPE_INT;
            break;
        }
    }

    // The values start on a four-byte boundary.
    padding = position % 4;
    if (padding != 0) {
        position += 4 - padding;
    }

    for (i = 0; i < count; i++) {
        argument.type = types[i];
        switch (argument.type) {
        case SPI_STACK_TYPE_STRING:
            argument.value.string = &buffer[position];
            length = strlen(argument.value.string) + 1;
            padding = length % 4;
            if (padding != 0) {
                length += 4 - padding;
            }
            position += length;
            break;
        case SPI_STACK_TYPE_FLOAT:
            argument.value.real = *(float *)&buffer[position];
            position += 4;
            break;
        case SPI_STACK_TYPE_INT:
            argument.value.integer = *(int *)&buffer[position];
            position += 4;
            break;
        }
        PushStack(argument);
    }
    return count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", GetArgBin__18CScriptInterpreterFv);
#endif
#ifdef NONMATCHING
int CScriptInterpreter::GetArg() {
    char text[SPI_TOKEN_SIZE];
    SPI_STACK argument;
    char *value_text;
    char *next;
    int count;
    int more;
    int quoted;
    int length;
    int c;
    int following;
    int i;
    int type;
    int invalid;
    int non_numeric;
    char quotes;

    count = 0;
    if (!SkipSpace(*this)) {
        return 0;
    }
    more = 1;
    do {
        if (!SkipSpace(*this)) {
            return count;
        }

        // Gather the text of one argument, up to a comma or semicolon outside quotes.
        quoted = 0;
        length = 0;
        for (;;) {
            if (!get(&c)) {
                return count;
            }
            if (c == '"') {
                quoted ^= 1;
            }
            if (quoted) {
                if (!(c & 0x80)) {
                    if (c == '\\') {
                        if (!get(&following)) {
                            back();
                        } else if (following == '"') {
                            c = '"';
                        } else {
                            back();
                        }
                    }
                } else if (c < 0xA1 || c > 0xDF) {
                    // The lead byte of a two-byte Shift-JIS character.
                    text[length++] = c;
                    if (!get(&c)) {
                        return count;
                    }
                }
            }
            if (!quoted) {
                if (c == ',') {
                    break;
                }
                if (c == ';') {
                    more = 0;
                    break;
                }
            }
            text[length++] = c;
        }
        if (length == 0 && c == ';') {
            return count;
        }
        text[length] = '\0';
        count++;

        // Tell the kind of the argument from its text.
        i = 0;
        type = SPI_STACK_TYPE_INT;
        invalid = 0;
        quotes = text[0] == '"';
        non_numeric = 0;
        if (text[length - 1] == '"') {
            text[length - 1] = '\0';
            quotes++;
        }
        for (; text[i] != '\0'; i++) {
            if (quotes == 0) {
                if (text[i] == '.') {
                    type = SPI_STACK_TYPE_FLOAT;
                }
                if (CheckChar(text[i]) && text[i] != '-' && text[i] != '.' &&
                    (text[i] < '0' || text[i] > '9')) {
                    non_numeric = 1;
                }
                if (!CheckChar(text[i])) {
                    text[i] = '\0';
                    break;
                }
            }
        }
        if (quotes == 2) {
            type = SPI_STACK_TYPE_STRING;
        }
        if (non_numeric && type != SPI_STACK_TYPE_STRING) {
            invalid = 1;
        }
        if (i == 0) {
            invalid = 1;
        }

        argument.type = type;
        if (invalid) {
            argument.value.string = NULL;
            argument.type = SPI_STACK_TYPE_INVALID;
        }

        value_text = text;
        if (type == SPI_STACK_TYPE_STRING) {
            // The text inside the quotes is kept in the string buffer.
            value_text = &text[1];
            next = string_buff_next;
            if (next + strlen(value_text) + 1 > string_buff + string_buff_size) {
                printf("SPI string buffer over!!\n");
                argument.value.string = NULL;
            } else {
                argument.value.string = next;
                strcpy(next, value_text);
                string_buff_next += strlen(value_text) + 1;
            }
        }
        if (argument.type == SPI_STACK_TYPE_INT) {
            argument.value.integer = atoi(value_text);
        }
        if (argument.type == SPI_STACK_TYPE_FLOAT) {
            argument.value.real = atof(value_text);
        }
        PushStack(argument);
    } while (more);
    return count;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", GetArg__18CScriptInterpreterFv);
#endif
#ifdef NONMATCHING
// Defined in scriptinterpreter.hpp.
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", back__9input_strFv);
#endif
#ifdef NONMATCHING
int CScriptInterpreter::SearchCommand(int *tag_index) {
    char name[SPI_TOKEN_SIZE];
    SPI_TAG_HASH *link;
    s16 index;
    int length;
    int c;
    int i;

    if (binary) {
        if (position < size) {
            index = *(s16 *)&buffer[position];
            position += 2;
            *tag_index = index;
            return index >= 0;
        }
        return 0;
    }

    if (!SkipSpace(*this)) {
        return 0;
    }
    length = 0;
    for (;;) {
        if (!get(&c)) {
            return 0;
        }
        if (!CheckChar(c) || c == ';') {
            break;
        }
        name[length++] = c;
    }
    // The semicolon ends the arguments, so it is read again by GetArg.
    if (c == ';') {
        back();
    }
    name[length] = '\0';

    if (name[0] >= 'A' && name[0] <= 'Z') {
        if (hash_table == NULL) {
            for (i = 0; i < tag_count; i++) {
                if (strcmp(tag[i].name, name) == 0) {
                    *tag_index = i;
                    return 1;
                }
            }
        } else {
            for (link = hash_table[hash(name)]; link != NULL; link = link->next) {
                if (strcmp(name, link->name) == 0) {
                    *tag_index = link->index;
                    return 1;
                }
            }
        }
    }
    *tag_index = -1;
    return 1;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SearchCommand__18CScriptInterpreterFPi);
#endif
#ifdef NONMATCHING
/**
 * Moves a reader past spaces, tabs and line breaks; gives non-zero when text
 * remains to be read.
 *
 */
static int SkipSpace(input_str &in) {
    while (in.position < in.size && !CheckChar(in.buffer[in.position])) {
        in.position++;
    }
    return in.position < in.size;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", SkipSpace__FR9input_str);
#endif
#ifdef NONMATCHING
/**
 * Tells whether a character is part of a word: gives 0 for a space, tab or
 * line break and 1 for anything else.
 *
 */
static int CheckChar(char c) {
    return c != '\r' && c != '\n' && c != '\t' && c != ' ';
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", CheckChar__Fc);
#endif
#ifdef NONMATCHING
/**
 * Overwrites the line comments and block comments of a text script with
 * spaces, so that the parser passes over them.
 *
 */
static void PreProcess(input_str &in) {
    char *text = in.buffer;
    int i = 0;

    while (i < in.size) {
        if (text[i] == '/' && text[i + 1] == '/') {
            for (; i < in.size; i++) {
                if (text[i] == '\n' || text[i] == '\r') {
                    break;
                }
                text[i] = ' ';
            }
        }
        if (text[i] == '/' && text[i + 1] == '*') {
            for (; i < in.size; i++) {
                if (text[i] == '*' && text[i + 1] == '/') {
                    text[i] = ' ';
                    text[i + 1] = ' ';
                    break;
                }
                text[i] = ' ';
            }
        } else {
            i++;
        }
    }
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/scriptinterpreter", PreProcess__FR9input_str);
#endif

// Constants (.rodata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scriptinterpreter", at_215__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scriptinterpreter", at_382__DATA);
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scriptinterpreter", at_524__DATA);

// Small initialised data (.sdata)
INCLUDE_RODATA("ps2/asm/pal/nonmatchings/scriptinterpreter", at_165__DATA);
