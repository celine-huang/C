#include <stdio.h>

typedef struct object {
    int weight;
    int value;
} Object;

typedef struct solution {
    int weight;
    int value;
} Solution;


Solution add (Solution solution, int solutionNum, Object *object, int n, int W) {
    if(solutionNum <= 0 || solution.weight > W)
        return solution;
    if((solutionNum & 1) != 0){
        solution.weight += object[n].weight;
        solution.value += object[n].value;
        return (add(solution, solutionNum >> 1, object, n - 1, W)); 
    }else
        return (add(solution, solutionNum >> 1, object, n - 1, W));
}

Solution better (Solution a, Solution b, int W) {
    return ((b.weight <= W && b.value > a.value) ? b : a);
}

Solution best (Solution solution, int solutionNum, Object *object, int n, int W) {
    if(solutionNum <= 0)
        return solution;
    Solution replace = {0, 0};
    solution = add(solution, solutionNum, object, n, W);
    return (better(best(replace, solutionNum - 1, object, n, W), solution, W));
}

int main (void) {
    int n, W;
    scanf("%d%d", &n, &W);
    Object object[n];
    int solutionNum = 1;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &object[i].weight, &object[i].value);
        solutionNum *= 2;
    }
    Solution solution = {0, 0};
    solution = best(solution, solutionNum - 1, object, n - 1, W);
    printf("%d\n", solution.value);
    return 0;
}
