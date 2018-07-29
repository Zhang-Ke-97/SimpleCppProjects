#ifndef _YANG_HUI_H
#define _YANG_HUI_H

/**
 * allocate memory by reference
 * @param triangle [pointer as 2D array]
 * @param SIZE     [row and col number of 2D array]
 */
void allocate_mem(unsigned long** &triangle, int SIZE);

/**
 * allocate memory by pointer
 * @param triangle [addr of the pointer as 2D array]
 * @param SIZE     [row and col number of 2D array]
 */
void allocate_mem(unsigned long*** triangle, int SIZE);

// initialize two sides with 1lu
void set_two_sides(unsigned long** triangle, int SIZE);

// set values to all members in triangle
void set_value(unsigned long** triangle, int SIZE);

// recusively calculate the triangle[i][j]
void cal_part(unsigned long** triangle, int SIZE, int i, int j);

// allocate memory by reference and set value for triangle
void build(unsigned long** &triangle, int SIZE);

// allocate memory by pointer and set value for triangle
void build(unsigned long*** triangle, int SIZE);

// output the triangle to console
void show(unsigned long** triangle, int SIZE);

// free memorys by reference
void destroy(unsigned long** &triangle, int SIZE);

// free memorys by pointer
void destroy(unsigned long*** triangle, int SIZE);

#endif
