#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *mp3 = fopen("music.mp3", "rb"); // Abre o MP3 para leitura binária
    if (!mp3) {
        printf("Erro ao abrir music.mp3\n");
        return 1;
    }
    
    // Obtém o tamanho do arquivo
    fseek(mp3, 0, SEEK_END);
    long tamanho = ftell(mp3);
    rewind(mp3);
    
    // Aloca memória para armazenar os bytes
    unsigned char *buffer = (unsigned char *)malloc(tamanho);
    if (!buffer) {
        printf("Erro ao alocar memória\n");
        fclose(mp3);
        return 1;
    }
    
    fread(buffer, 1, tamanho, mp3); // Lê o MP3 para o buffer
    fclose(mp3);
    
    // Abre um arquivo TXT para armazenar os bytes
    FILE *saida = fopen("music_array.txt", "w");
    if (!saida) {
        printf("Erro ao criar music_array.txt\n");
        free(buffer);
        return 1;
    }
    
    // Escreve o array no arquivo
    fprintf(saida, "unsigned char music_mp3[] = {\n");
    for (long i = 0; i < tamanho; i++) {
        fprintf(saida, "0x%02X%s", buffer[i], (i + 1) % 16 == 0 ? ",\n" : ", ");
    }
    fprintf(saida, "\n};\nunsigned int music_mp3_len = %ld;\n", tamanho);
    
    fclose(saida);
    free(buffer);
    
    printf("Arquivo music_array.txt gerado com sucesso!\n");
    return 0;
}