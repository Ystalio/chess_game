void print_binary_chess_table(int (*b)[8]){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d",b[i][j]);
        }
        printf("\n");
    }
}
