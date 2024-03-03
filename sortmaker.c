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
        fprintf(f, "\tchar *sort[10000];\n");
        
        for (int k = 0; k <= 9; k++) {
            fprintf(f, "\tsort[%d] = \"000%d\";\n", k, k);
        }
        
        for (int j = 1; j <= 9; j++) {
            for (int k = 0; k < j; k++) {
                fprintf(f, "\tsort[%d%d] = \"00%d%d\";\n", j, k, k, j);
            }
            for (int k = j; k <= 9; k++) {
                fprintf(f, "\tsort[%d%d] = \"00%d%d\";\n", j, k, j, k);
            }
        }
        
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j < i; j++) { // i > j
                for (int k = 0; k < j; k++) { //i > j > k
                    fprintf(f, "\tsort[%d%d%d] = \"0%d%d%d\";\n", i, j, k, k, j, i);
                }
                for (int k = j; k < i; k++) { // i > k > j
                    fprintf(f, "\tsort[%d%d%d] = \"0%d%d%d\";\n", i, j, k, j, k, i);
                }
                for (int k = i; k <= 9; k++) { // k > j > i
                    fprintf(f, "\tsort[%d%d%d] = \"0%d%d%d\";\n", i, j, k, j, i, k);
                }
            }
            for (int j = i; j <= 9; j++) { 
                for (int k = 0; k < i; k++) { // k < i <= j;
                    fprintf(f, "\tsort[%d%d%d] = \"0%d%d%d\";\n", i, j, k, k, i, j);
                }
                for (int k = i; k < j; k++) { // i < k < j
                    fprintf(f, "\tsort[%d%d%d] = \"0%d%d%d\";\n", i, j, k, i, k, j);
                }
                for (int k = j; k <= 9; k++) { // i < j < k
                    fprintf(f, "\tsort[%d%d%d] = \"0%d%d%d\";\n", i, j, k, i, j, k);
                }
            }
        }
        
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j < i; j++) { // j < i
                for (int k = 0; k < j; k++) { // k < j < i
                    for (int l = 0; l < k; l++) { // l < k < j < i
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, l, k, j, i);
                    }
                    for (int l = k; l < j; l++) { // k < l < j < i
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, k, l, j, i);
                    }
                    for (int l = j; l < i; l++) { // k < j < l < i
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, k, j, l, i);
                    }
                    for (int l = i; l <= 9; l++) { // k < j < i < l
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, k, j, i, l);
                    }
                }
                for (int k = j; k < i; k++) { // j < k < i
                    for (int l = 0; l < j; l++) { // l < j < k < i
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, l, j, k, i);
                    }
                    for (int l = j; l < k; l++) { // j < l < k < i
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, j, l, k, i);
                    }
                    for (int l = k; l < i; l++) { // j < k < l < i
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, j, k, l, i);
                    }
                    for (int l = i; l <= 9; l++) { // j < k < i < l
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, j, k, i, l);
                    }
                }
                for (int k = i; k <= 9; k++) { // j < i < k
                    for (int l = 0; l < j; l++) { // l < j < i < k
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, l, j, i, k);
                    }
                    for (int l = j; l < i; l++) { // j < l < i < k
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, j, l, i, k);
                    }
                    for (int l = i; l < k; l++) { // j < i < l < k
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, j, i, l, k);
                    }
                    for (int l = k; l <= 9; l++) { // j < i < k < l
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, j, i, k, l);
                    }
                }
            }
            for (int j = i; j <= 9; j++) { // i < j
                for (int k = 0; k < i; k++) { // k < i < j
                    for (int l = 0; l < k; l++) { // l < k < i < j
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, l, k, i, j);
                    }
                    for (int l = k; l < i; l++) { // k < l < i < j
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, k, l, i, j);
                    }
                    for (int l = i; l < j; l++) { // k < i < l < j
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, k, i, l, j);
                    }
                    for (int l = j; l <= 9; l++) { // k < i < j < l
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, k, i, j, l);
                    }
                }
                for (int k = i; k < j; k++) { // i < k < j
                    for (int l = 0; l < i; l++) { // l < i < k < j
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, l, i, k, j);
                    }
                    for (int l = i; l < k; l++) { // i < l < k < j
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, i, l, k, j);
                    }
                    for (int l = k; l < j; l++) { // i < k < l < j
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, i, k, l, j);
                    }
                    for (int l = j; l <= 9; l++) { // i < k < j < l
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, i, k, j, l);
                    }
                }
                for (int k = j; k <= 9; k++) { // i < j < k
                    for (int l = 0; l < i; l++) { // l < i < j < k
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, l, i, j, k);
                    }
                    for (int l = i; l < j; l++) { // i < l < j < k
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, i, l, j, k);
                    }
                    for (int l = j; l < k; l++) { // i < j < l < k
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, i, j, l, k);
                    }
                    for (int l = k; l <= 9; l++) { // i < j < k < l
                        fprintf(f, "\tsort[%d%d%d%d] = \"%d%d%d%d\";\n", i, j, k, l, i, j, k, l);
                    }
                }
            }
        }
        
        fprintf(f, "\tprintf(sort[atoi(argv[1])]);\n");
        fprintf(f, "\treturn 0;\n}");
        fclose(f);
    }
    return 0;
}