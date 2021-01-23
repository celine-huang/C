#include <stdio.h>

int shiftadd(int *set, int n, int setnum, int sum, int k, int m){
  if(setnum <= 0 || sum > m){
    if(k <= 0)
      return sum;
    else
      return m + 1;
  }
  if((setnum & 1) != 0)
    shiftadd(set, n - 1, setnum >> 1, sum + set[n], k - 1, m);
  else
    shiftadd(set, n - 1, setnum >> 1, sum, k, m);
}

int count(int *set, int n, int k, int m, int setnum, int ct){
  if(setnum <= 0)
    return ct;
  int sum = shiftadd(set, n - 1, setnum, 0, k, m);
  if(sum <= m)
    return count(set, n, k, m, setnum - 1, ct + 1);
  else
    return count(set, n, k, m, setnum - 1, ct);
}

int main() {
  int k, n, m;
  scanf("%d%d%d", &k, &n, &m);
  int set[n];
  int setnum = 1;
  for(int i = 0; i < n; i++){
    scanf("%d", &set[i]);
    setnum *= 2;
  }
  printf("%d\n", count(set, n, k, m, setnum - 1, 0));
  return 0;
}
