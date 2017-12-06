#include <math.h>
#include <stdio.h>
#define XMAX 200
#define YMAX 100

struct point {
  int x, y;
};

struct rect {
  struct point pt1, pt2;
};

int main(void) {
  struct rect screen;
  struct point middle;
  struct point makepoint(int, int);
  struct point addpoint(struct point, struct point);
  int point_in_rect(struct point, struct rect);
  struct rect canon_rect(struct rect);

  screen.pt2 = makepoint(0, 0);
  screen.pt1 = makepoint(XMAX, YMAX);

  screen = canon_rect(screen);

  printf("screen: lower left (%d, %d), upper right (%d, %d)\n", screen.pt1.x,
         screen.pt1.y, screen.pt2.x, screen.pt2.y);

  middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                     (screen.pt1.y + screen.pt2.y) / 2);

  printf("middle: (%d, %d)\n", middle.x, middle.y);

  struct point sum = addpoint(screen.pt2, middle);

  printf("middle + max: (%d, %d)\n", sum.x, sum.y);

  printf("middle in screen? %d\n", point_in_rect(middle, screen));
  printf("sum in screen? %d\n", point_in_rect(sum, screen));

  return 0;
}

struct point makepoint(int x, int y) {
  struct point temp;
  temp.x = x;
  temp.y = y;
  return temp;
};

struct point addpoint(struct point p1, struct point p2) {
  p1.x = p1.x + p2.x;
  p1.y = p1.y + p2.y;
  return p1;
}

int point_in_rect(struct point p, struct rect r) {
  return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct rect canon_rect(struct rect r) {
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);

  return temp;
};
