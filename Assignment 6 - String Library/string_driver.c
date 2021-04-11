#include <stdio.h>

#include "include/personal_string.h"

void print_str_array(char **given_array);

int main() {
	printf("str_len: '%i'", str_len("Helloo")); // Expect '6'
	printf("\nall_letters: '%i'", all_letters("Helloo")); // Expect '1'
	printf("\nnum_in_range: '%i'", num_in_range("Helloo", 'a', 'l')); // Expect '3'
	printf("\ndiff: '%i'", diff("Helloo", "hellooo")); // Expect '3'

	char a[] = "Hello";
	shorten(a, 3);
	printf("\nshorten: '%s'", a); // Expect 'Hel'
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
	printf("\nfind: '%i'", find(e, "Hel")); // Expect '3'

	char *f = "Test";
	char *ptr_a = ptr_to(f, "es");
	printf("\nptr_to: '%p' ... Original address: '%p'", ptr_a, f); // Expect f + 1

	char *g = "     ";
	printf("\nis_empty: '%i'", is_empty(g)); // Expect '1'

	char *h = "Test1", *i = "testTWO";
	char *zipped = str_zip(h, i);
	printf("\nstr_zip: '%s'", zipped);

	char j[] = "ThIs sEntEnce HaD  One  cApital leTTer.";
	capitalize(j);
	printf("\ncapitalize: '%s'", j);

	char *k = "Test Sentence.", *l = "Dest Sentence.";
	printf("\nstrcmp_ign_case: '%i'", strcmp_ign_case(k, l));

	char m[] = "This sentence should only get the last 4 chars.";
	take_last(m, 4);
	printf("\ntake_last: '%s'", m);

	char *n = "There's always money in the banana stand.";
	printf("\ndedup: '%s'", dedup(n));

	char *o = "Five.";
	printf("\npad: '%s'", pad(o, 3));

	char *p = "This is a test sentence.";
	printf("\nends_with_ignore_case: '%i'", ends_with_ignore_case(p, "EnCe.")); // Expect '1'

	char *q = "RepeatThis";
	printf("\nrepeat: '%s'", repeat(q, 3, ','));

	char *r[] = {"Washington", "Adams", "Jefferson"};
	printf("\nstr_connect: '%s'", str_connect(r, 3, '+'));

	char *s[] = {"One", "", "Dos", "", "Tres", '\0'};
	rm_empties(s);
	printf("\nrm_empties: ");
	print_str_array(s);

	char *t = "I am ready for a nice vacation";
	printf("\nprint_str_array: ");
	print_str_array(str_chop_all(t, ' '));
}

void print_str_array(char **given_array) {
	printf("{");
	for (int i = 0; given_array[i] != 0; i++)
		printf("\"%s\", ", given_array[i]);

	printf("NULL}");
}