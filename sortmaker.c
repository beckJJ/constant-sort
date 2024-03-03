#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen("constsort.c", "w");
    if (f) {
        fprintf(f, "#include <stdio.h>\n");
        fprintf(f, "#include <stdlib.h>\n\n");
        fprintf(f, "int main(int argc, char *argv[])\n{\n");
        fprintf(f, "\tchar *sort[1000];\n");
        
        for (int k = 0; k <= 9; k++) {
            fprintf(f, "\tsort[%d] = \"00%d\";\n", k, k);
        }
        
        for (int j = 1; j <= 9; j++) {
            for (int k = 0; k < j; k++) {
                fprintf(f, "\tsort[%d%d] = \"0%d%d\";\n", j, k, k, j);
            }
            for (int k = j; k <= 9; k++) {
                fprintf(f, "\tsort[%d%d] = \"0%d%d\";\n", j, k, j, k);
            }
        }
        
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j < i; j++) { // i > j
                for (int k = 0; k < j; k++) { //i > j > k
                    fprintf(f, "\tsort[%d%d%d] = \"%d%d%d\";\n", i, j, k, k, j, i);
                }
                for (int k = j; k < i; k++) { // i > k > j
                    fprintf(f, "\tsort[%d%d%d] = \"%d%d%d\";\n", i, j, k, j, k, i);
                }
                for (int k = i; k <= 9; k++) { // k > j > i
                    fprintf(f, "\tsort[%d%d%d] = \"%d%d%d\";\n", i, j, k, j, i, k);
                }
            }
            for (int j = i; j <= 9; j++) { 
                for (int k = 0; k < i; k++) { // k < i <= j;
                    fprintf(f, "\tsort[%d%d%d] = \"%d%d%d\";\n", i, j, k, k, i, j);
                }
                for (int k = i; k < j; k++) { // i < k < j
                    fprintf(f, "\tsort[%d%d%d] = \"%d%d%d\";\n", i, j, k, i, k, j);
                }
                for (int k = j; k <= 9; k++) { // i < j < k
                    fprintf(f, "\tsort[%d%d%d] = \"%d%d%d\";\n", i, j, k, i, j, k);
                }
            }
        }
        
        fprintf(f, "\tprintf(sort[atoi(argv[1])]);\n");
        fprintf(f, "\treturn 0;\n}");
        fclose(f);
    }
    return 0;
}