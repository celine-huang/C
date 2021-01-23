#include <stdio.h>

int shiftadd(int *set, int n, int setnum, int sum, int k){
  if(setnum <= 0 || sum > k)
    return sum;
  if((setnum & 1) != 0)
    shiftadd(set, n - 1, setnum >> 1, sum + set[n], k);
  else
    shiftadd(set, n - 1, setnum >> 1, sum, k);
}

int count(int *set, int n, int setnum, int k, int ct){
  if(setnum < 0)
    return ct;
  int num = shiftadd(set, n-1, setnum, 0, k);
  if(num == k)
    ct = count(set, n, setnum-1, k, ct + 1);
  else
    ct = count(set, n, setnum-1, k, ct);
}

int main() {
  int n;
  scanf("%d", &n);
  int set[n];
  int setnum = 1;
  for(int i = 0; i < n; i++){
    scanf("%d", &set[i]);
    setnum *= 2;
  }
  int k;
  while(scanf("%d", &k) != EOF){
    int ct = count(set, n, setnum-1, k, 0);
    printf("%d\n", ct);
  }
  return 0;
}
