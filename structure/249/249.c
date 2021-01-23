#include <stdio.h>
#include <string.h>
#define STRINGLENGTH 32
#define EMPLOYEENUM 32

typedef struct employee {
    int id;
    char firstname[STRINGLENGTH];
    char lastname[STRINGLENGTH];
    int bossid;
    int boss[EMPLOYEENUM];
    int bossnum;
} Employee;

typedef struct request {
    char firstname1[STRINGLENGTH];
    char lastname1[STRINGLENGTH];
    int employee1;
    char firstname2[STRINGLENGTH];
    char lastname2[STRINGLENGTH];
    int employee2;
} Request;

int findemployee (char *firstname, char *lastname, Employee *employee, int employeenum) {
    int index = 0;
    while (index != employeenum){
        if(strcmp(firstname, employee[index].firstname) == 0 && strcmp(lastname, employee[index].lastname) == 0)
            return index;
        index++;
    }
    return(-1);
}

int findid (int id, Employee *employee) {
    int index = 0;
    while(id != employee[index].id)
        index++;
    return index;
}

int findboss (int n, int employeenum, Employee *employee, int index) {
    if(employee[employeenum].bossid != employee[employeenum].id){
		employee[n].boss[index] = findid(employee[employeenum].bossid, employee);
        return findboss(n, employee[n].boss[index], employee, index + 1);	
	}
    return index;
}

void readinfo (Employee *employee, int n) {
    scanf("%d", &employee[n].id);
    scanf("%s", employee[n].firstname);
    scanf("%s", employee[n].lastname);
    scanf("%d", &employee[n].bossid);
}

void relation (int employee1, int employee2, Employee *employee) {
    int i = 0;
    while(i < employee[employee1].bossnum){
        if(employee[employee[employee1].boss[i]].bossid == employee[employee2].id){
            printf("subordinate\n");
            return;
        }
        i++;
    }
    i = 0;
    while(i < employee[employee2].bossnum){
        if(employee[employee[employee2].boss[i]].bossid == employee[employee1].id){
            printf("supervisor\n");
            return;
        }
        i++;
    }
    i = 0;
    int j = 0;
    while(i < employee[employee1].bossnum){
        while(j < employee[employee2].bossnum){
            if(employee[employee1].boss[i] == employee[employee2].boss[j]){
                printf("colleague\n");
                return;
            }
            j++;
        }
        i++;
    }
    printf("unrelated\n");
    return;
}

void process (Request *request, int n){
    scanf("%s", request[n].firstname1);
    scanf("%s", request[n].lastname1); 
    scanf("%s", request[n].firstname2);
    scanf("%s", request[n].lastname2);
}

int main (void) {
    int n;
    scanf("%d", &n);
    Employee employee[n];
    for(int i = 0; i < n; i++)
        readinfo(employee, i);
    for(int i = 0; i < n; i++)
        employee[i].bossnum = findboss(i, i, employee, 0);
    int m;
    scanf("%d", &m);
    Request request[m];
    for(int i = 0; i < m; i++)
        process(request, i);
    for(int i = 0; i < m; i++){
		request[i].employee1 = findemployee(request[i].firstname1, request[i].lastname1, employee, n);
		request[i].employee2 = findemployee(request[i].firstname2, request[i].lastname2, employee, n);        
		relation(request[i].employee1, request[i].employee2, employee);
    }
	return 0;
}

