#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/hash.h"
#include "../include/utils.h"

char *output_file_folder = "output/inter_submission/";

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: Inter Submission --> ./leaf_process <file_path> 0\n");
        printf("Usage: Final Submission --> ./leaf_process <file_path> <pipe_write_end>\n");
        return -1;
    }
    //TODO(): get <file_path> <pipe_write_end> from argv[]
    char *file_path = argv[1];
    int pipe_write_end = atoi(argv[2]);


    //create the hash of given file
    int hash_value;
    hash_data_block(hash_value, file_path);

    
    //construct string write to pipe. The format is "<file_path>|<hash_value>"
    char string_to_write[strlen(file_path) + strlen(hash_value) + 2];
    snprintf(string_to_write, sizeof(string_to_write), "%s|%d", *file_path, hash_value);
    



    if(1){
        //TODO(inter submission)
        //TODO(overview): create a file in output_file_folder("output/inter_submission/root*") and write the constructed string to the file

        if (mkdir("output/inter_submission/root*", 0777) < 0){
                printf("ERROR: mkdir output/inter_submission/root* failed\n");
                exit(1);
            }
        FILE *f = fopen("File 1", "w"); //TODO: change to "File 1" to some variable for "File x"
        if (!f) {
            perror("Error: Opening Leaf file failed");
            exit(1);
        }
        fprintf(f, "%s", string_to_write);
        fclose(f);


        char* extracted_f=extract_filename(file_path);
        char* extracted_root=extract_root_directory(file_path);


        //TODO(step3): get the location of the new file (e.g. "output/inter_submission/root1" or "output/inter_submission/root2" or "output/inter_submission/root3")
        //TODO(step4): create and write to file, and then close file
        //TODO(step5): free any arrays that are allocated using malloc!! Free the string returned from extract_root_directory()!! It is allocated using malloc in extract_root_directory()

    }else{
        //TODO(final submission): write the string to pipe

        exit(0);

    }

    exit(0);
}
