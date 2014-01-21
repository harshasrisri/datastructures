#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Children (node->children)
#define WS (node->ws)
#define Word (node->ws->word)
#define WC (node->ws->count)

#ifndef DEBUG
#define DEBUG 0
#endif

#define DBG(str) if (DEBUG) fprintf (stderr, "Debug | %s : %s\n", __func__, (str))

struct word_struct {
	char *word;
	int count;
};

struct node {
	struct node *children[26];
	struct word_struct *ws;
};

struct node *node_head;
char line[50];
int key;

void print (struct node *node) {
	int i;

	if (WS) {
		printf ("%s %d\n", Word, WC);
		free (Word);
		free (WS);
	}

	for (i = 0; i < 26; i++)
		if (Children[i])
			print (Children[i]);

	free (node);
}

struct node *init_node () {
	int i;
	struct node *node;

	node = (struct node *) malloc (sizeof (struct node));
	WS = NULL;

	for (i = 0; i < 26; i++)
		Children[i] = NULL;

	return node;
}

void insert (struct node *node, char *word) {

	if (!*word) {
		if (!WS) {
			WS = (struct word_struct *) malloc (sizeof (struct word_struct));
			Word = strdup (line);
		}
		WC++;
		return;
	}

	key = word[0] - 'a';

	if (!Children[key])
		Children[key] = init_node ();

	insert (Children[key], &word[1]);
}

int main () {
	node_head = init_node ();

	while (fgets (line, 50, stdin)) {
		* (char *) (strchr (line, '\n')) = '\0';
		insert (node_head, line);
	}

	print (node_head);

	return 0;
}
