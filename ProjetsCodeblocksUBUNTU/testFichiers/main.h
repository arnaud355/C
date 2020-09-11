FILE* fopen(const char* nomDuFichier, const char* modeOuverture);     /*la fonction fopen contient des adresses
                                                                        on lui precise qu'on veut les variables
                                                                        contenu à ces adresses. Le type FILE
                                                                        est une struct prédéfinie dans stdio.h
                                                                        on pointe avec * sur fopen pour avoir
                                                                        sa valeur de variable.
                                                                    (ou plutôt celles des paramètres)*/
int fputc(int caractere, FILE* pointeurSurFichier);
int fputs(const char* chaine, FILE* pointeurSurFichier);
int fclose(FILE* pointeurSurFichier);
