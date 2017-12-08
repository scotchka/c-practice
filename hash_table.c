#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
  struct nlist *next;
  char *key;
  char *value;
};

#define HASHSIZE 5

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
  unsigned hashval;
  for (hashval = 0; *s != '\0'; ++s)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL;
       np = np->next) // search linked list attached to pointer array
    if (strcmp(s, np->key) == 0)
      return np;
  return NULL;
}

struct nlist *install(char *key, char *value) {
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(key)) == NULL) {
    np = (struct nlist *)malloc(sizeof *np);
    if (np == NULL || (np->key = strdup(key)) == NULL) // out of memory
      return NULL;
    hashval = hash(key);
    np->next = hashtab[hashval]; // point to old head
    hashtab[hashval] = np;
  } else
    free((void *)np->value); // deallocate previous

  if ((np->value = strdup(value)) == NULL) // assign value
    return NULL;

  return np;
}

int main(void) {
  int i;
  char *words[] = {"apple", "berry", "cherry"};

  for (i = 0; i < 3; ++i)
    install(words[i], words[2 - i]);

  for (i = 0; i < HASHSIZE; ++i)
    if (hashtab[i] != NULL)
      printf("%dth position is %s: %s\n", i, hashtab[i]->key,
             hashtab[i]->value);
    else
      printf("%dth position is null\n", i);

  printf("%s\n", lookup("berry")->value);
}
