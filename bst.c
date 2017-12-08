#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXWORD 100
typedef struct tnode *Treeptr;

typedef struct tnode {
  char *word;
  int count;
  Treeptr left;
  Treeptr right;
} Treenode;

Treeptr addtree(Treeptr, char *);
void treeprint(Treeptr);
int getword(char *, int);

int main(void) {
  Treeptr root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);
  return 0;
}

Treeptr talloc(void);
char *str_dup(char *);

Treeptr addtree(Treeptr p, char *w) {
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = str_dup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

void treeprint(Treeptr p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

#include <stdlib.h>

Treeptr talloc(void) { return (Treeptr)malloc(sizeof(Treenode)); }

char *str_dup(char *s) {
  char *p;

  p = (char *)malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}
