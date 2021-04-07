#include <stdio.h>
#include "include/personal_string.h"

int main() {
	printf("str_len: '%i'", str_len("Helloo")); // Expect '6'
	printf("\nall_letters: '%i'", all_letters("Helloo")); // Expect '1'
	printf("\nnum_in_range: '%i'", num_in_range("Helloo", 'a', 'l')); // Expect '3'

	char a[] = "Hello";
	shorten(a, 3);
	printf("\nshorten: '%s' from '%s'", a, "Hello"); // Expect 'Hel'
	printf("\nlen_diff: '%i'", len_diff("Hello", a)); // Expect '2'

	char b[] = "   Hello ";
	rm_left_space(b);
	printf("\nrm_left_space: '%s'", b); // Expect 'Hello '

	char c[] = " Hello   ";
	rm_right_space(c);
	printf("\nrm_right_space: '%s'", c); // Expect ' Hello'

	char d[] = "   Hello    ";
	rm_space(d);
	printf("\nrm_space: '%s'", d); // Expect 'Hello'

	char *e = "   Hello    ";
	printf("\nfind: '%i'", find(e, "  ")); // Expect '5'

	char *f = "Test";
	void *ptr_a = ptr_to(f, "es");
	printf("\nptr_to: '%x' ... Original address: '%x'", ptr_a, f); // Expect f + 1

	char *g = "     ";
	printf("\nis_empty: '%i'", is_empty(g)); // Expect '1'

	char *h = "Test1", *i = "testTWO";
	char *zipped = str_zip(h, i);
	printf("\nstr_zip: '%s'", zipped);

	char j[] = "ThIs sEntEnce HaD  One  cApital leTTer.";
	capitalize(j);
	printf("\ncapitalize: '%s'", j);

	char k[] = "This sentence should only get the last 4 chars.";
	take_last(k, 4);
	printf("\ntake_last: '%s'", k);

	char *l = "There's always money in the banana stand.";
	printf("\ndedup: '%s'", dedup(l));

	char *m = "This is a test sentence.";
	printf("\npad: '%s'", pad(m, 2)); // TODO: TEST THIS MORE
}