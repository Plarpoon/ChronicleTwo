/**
 *
 * Holds the matrix used to transform collision triangle normals on PC.
 *
 */
float collision_normal_transform[4][4];

/**
 *
 * Stores the transform for subsequent collision triangle operations.
 *
 */
void pre_trance_normal(float (*matrix)[4]) {
    for (int column = 0; column < 4; column++) {
        for (int row = 0; row < 4; row++) {
            collision_normal_transform[column][row] = matrix[column][row];
        }
    }
}
