#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
long calculate_total_wrapping_paper(const char *filename);
long calculate_total_ribbon(const char *filename);

int main() {
    const char *filename = "2.in";  // Filename with the dimensions

    // Calculate the total wrapping paper needed
    long total_paper = calculate_total_wrapping_paper(filename);
    printf("Total wrapping paper needed: %ld square feet\n", total_paper);

    // Calculate the total ribbon needed
    long total_ribbon = calculate_total_ribbon(filename);
    printf("Total ribbon needed: %ld feet\n", total_ribbon);

    return 0;
}

// Part 1: Calculate the total wrapping paper needed
long calculate_total_wrapping_paper(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    long total_paper = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        int l, w, h;
        // Parse the dimensions from the line
        if (sscanf(line, "%dx%dx%d", &l, &w, &h) == 3) {
            // Calculate surface areas of the three sides
            int lw = l * w;
            int wh = w * h;
            int hl = h * l;

            // Calculate the surface area of the box
            int surface_area = 2 * (lw + wh + hl);

            // Determine the smallest side area
            int slack = lw < wh ? (lw < hl ? lw : hl) : (wh < hl ? wh : hl);

            // Total wrapping paper needed for this present
            int total_for_present = surface_area + slack;

            // Add to the running total
            total_paper += total_for_present;
        }
    }

    fclose(file);
    return total_paper;
}

// Part 2: Calculate the total ribbon needed
long calculate_total_ribbon(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    long total_ribbon = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        int l, w, h;
        // Parse the dimensions from the line
        if (sscanf(line, "%dx%dx%d", &l, &w, &h) == 3) {
            // Calculate the perimeters of the three sides
            int perimeter1 = 2 * (l + w);
            int perimeter2 = 2 * (w + h);
            int perimeter3 = 2 * (h + l);

            // Determine the smallest perimeter
            int smallest_perimeter = perimeter1 < perimeter2 ? (perimeter1 < perimeter3 ? perimeter1 : perimeter3) : (perimeter2 < perimeter3 ? perimeter2 : perimeter3);

            // Calculate the volume of the box (for the bow)
            int volume = l * w * h;

            // Total ribbon needed for this present
            int total_for_present = smallest_perimeter + volume;

            // Add to the running total
            total_ribbon += total_for_present;
        }
    }

    fclose(file);
    return total_ribbon;
}

