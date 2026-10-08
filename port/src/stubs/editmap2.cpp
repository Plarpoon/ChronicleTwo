/**
 *
 * Calculates a horizontal plane normal for the PC port.
 *
 */
void PlaneNormalXZ(float *normal, float *p0, float *p1, float *p2) {
    float edge1_x = p1[0] - p0[0];
    float edge1_z = p1[2] - p0[2];
    float edge2_x = p2[0] - p0[0];
    float edge2_z = p2[2] - p0[2];
    normal[0] = 0.0f;
    normal[1] = edge1_z * edge2_x - edge1_x * edge2_z;
    normal[2] = 0.0f;
    normal[3] = 0.0f;
}
