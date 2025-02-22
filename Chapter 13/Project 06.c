\#include <stdio.h>
#include <string.h>
#include <ctype.h>

int string_to_compare(char* p, char* q) {

	while (*p && *q) {
		if (tolower(*p) != tolower(*q))
			return tolower(*p) - tolower(*q);

		p++;
		q++;
	}

	return (*p == '\0' && *q == '\0') ? 0 : (*p - *q);
}

int main(int argc, char* argv[]) {
	char* planets[] = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto" };
	int i, j;

	if (argc < 2) {
		fprintf(stderr, "Usage: planet planet_name...\n");
		return 1;
	}

	for (i = 1; i < argc; i++) {
		int planet_found = 0;
		for (j = 0; j < 9; j++) {
			if (string_to_compare(argv[i], planets[j]) == 0) {
				printf("%s is planet %d\n", argv[i], j + 1);
				planet_found = 1;
				break;
			}
		}
		if (!planet_found) {
			printf("%s is not a planet\n", argv[i]);
		}
	}

	return 0;
}