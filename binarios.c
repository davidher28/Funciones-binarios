#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Función que se encarga de volver un numero decimal a un número binario
int *CrearBin (int n){
    int z=32;
    int *y= calloc(z+1,sizeof(int));
    while (n>0){
        y[z]=n%2;
        n/=2;
        z--;
    }
    return y;
}


// Función que se encarga de retornar la negación de un numero binario
int *Not(int *h){
    int x;
    for (x=0;x<=32;x++){
        if (h[x]==1){
            while (x<=32){
                if (h[x]==1){
                    h[x]=0;
                }else{
                    h[x]=1;
                }
                x++;
            }
        }
    }
    return h;
}


// Función que se encarga de retornar la condicion logica AND entre dos binarios
int *And (int *bi, int *bi2){
    int i,x=32;
    int *n=calloc(x+1,sizeof(int));
    for (i=0;i<=32;i++){
        if(bi[i]==1 && bi2[i]==1){
            n[i]=1;
        }else{
            n[i]=0;
        }
    }
    return n;
}

// Función que se encarga de retornar la condicion logica OR entre dos binarios
int *Or(int *b,int *b2){
    int i,x=32;
    int *n2=calloc(x+1,sizeof(int));
    for (i=0;i<=32;i++){
        if((b[i]==1 && b2[i]==0) || (b[i]==0 && b2[i]==1) || (b[i]==1 && b2[i]==1)){
            n2[i]=1;
        }else{
            n2[i]=0;
        }
    }
    return n2;
}

// Función que se encarga de retornar la suma entre dos binarios 
int *SumarBin(int *bi, int *bi2){
    int x=32,k;
    int *nue=calloc(x+1,sizeof(int));
    int carry=0;
    for(k=32;k>=1;k--){
        if(bi[k]== 0 && bi2[k]==0){
            if(carry==1){
                nue[k]=1;
                carry=0;
            }else{
                nue[k]=0;
                carry=0;
            }
        }if(bi[k]==0 && bi2[k]==1){
            if(carry==1 || carry==0){
                nue[k]=1;
                carry=0;
            }
        }if(bi[k]==1 && bi2[k]==0){
            if(carry==1){
                nue[k]=0;
                carry=1;    
            }else{
                nue[k]=1;
                carry=0;
            }
        }if(bi[k]==1 && bi2[k]==1){
            if(k==1){
                if(carry==1){
                    nue[k]=1;
                    nue[0]=1;
                }else{
                    nue[k]=0;
                    nue[0]=1;
                }
            }else{
                if(carry==1){
                    nue[k]=1;
                    carry=1;
                }else{
                    nue[k]=0;
                    carry=1;
                }
            }
        }
    }
    return nue;
}


// Función que se encarga de retornar el corrimiento de un numero binario a la derecha (un solo bit)
int *CorrimientoDer(int *bin){
    int y,d=32;
    int *der= calloc(d,sizeof(int));
    for(y=1;y<=32;y++){
        if(y==1){
            der[y]=0;
            der[y+1]=bin[y];
        }else{
            der[y+1]=bin[y];
        }
    }
    return der;
}

// Función que se encarga de retornar el corrimiento de un numero binario a la izquierda (un solo bit)
int *CorrimientoIzq(int *b){
    int d,i=32;
    int *izq = calloc(i,sizeof(int));
    for(d=32;d>=1;d--){
        if(d==1){
            izq[d]=0;
            izq[d-1]=b[d];
        }else{
            izq[d-1]=b[d];
        }
    }
    return izq;
}

// Función que se encarga de retornar o el valor obtenido de sumarle uno al complemento lógico del número binario(su negacion).
int *Complementoa2(int *bi){
    int n=1,i;
    int *nb=calloc(32,sizeof(int));
    nb=Not(bi);
    printf("\nLa Negacion es:");
    for(i=0;i<=32;i++){
        printf("%d",nb[i]);
    }
    int *sum=calloc(32,sizeof(int));
    sum=CrearBin(n);

    int *sum2=calloc(32,sizeof(int));
    sum2=SumarBin(nb,sum);

    return sum2;
}


// Función que se encarga de volver un numero binario en un número decimal común
int Bin2Dec(int *binario){
    int temp=0,k=32,i;
    for(i=0;i<=32;i++){
        temp=temp+((binario[i]*pow(2,k-i)));
    }
    return temp;
}

// Función que se encarga de retornar si un numero es binario o no
int esBin(int *bin){
    for(int i=0;i<=32;i++){
        if(bin[i]==0 || bin[i]==1){
            return 1;
        }
    }
    return 0;
}


void main (){
    int n,x,u;
    printf ("Ingrese el primer entero\n");
    scanf ("%d",&n);
    printf ("Ingrese el segundo entero\n");
    scanf ("%d",&u);
    int *l;
    l=CrearBin(n);
    int *d;
    d=CrearBin(u);
    //Crear Binario
    printf ("El primer binario es: ");
    for (x=0;x<=32;x++){
        printf ("%d",l[x]);
    }
    printf ("\nEl segundo binario es:");
    for (x=0;x<=32;x++){
        printf ("%d",d[x]);
    }
    // Negación del binario
    int *s;
    s=Not(l);
    printf ("\nNegacion del primer binario dado:");
    for (x=0;x<=32;x++){
        printf ("%d",s[x]);
    }
    // Operación And
    int *and;
    and=And(l,d);
    printf ("\nOperacion AND entre los binarios dados:");
    for (x=0;x<=32;x++){
        printf ("%d",and[x]);
    }
    // Operación Or
    int *or;
    or=Or(l,d);
    printf ("\nOperacion OR entre los biinarios dados:");
    for (x=0;x<=32;x++){
        printf ("%d",or[x]);
    }
    // Operación Suma de binarios
    int *sum;
    sum=SumarBin(l,d);
    printf ("\nOperacion SUMA entre los binarios dados:");
    for (x=0;x<=32;x++){
        printf ("%d",sum[x]);
    }
    // Operación Corrimiento a la derecha
    int *der;
    der=CorrimientoDer(l);
    printf("\nBinario desplazado hacia la derecha:");
    for (x=0;x<=32;x++){
        printf("%d",der[x]);
    }
    // Operación Corrimiento a la izquierda
    int *izq;
    izq=CorrimientoIzq(l);
    printf("\nBinario desplazado hacia la izquierda:");
    for (x=0;x<=32;x++){
        printf("%d",izq[x]);
    }
    // Operación Complementoa2
    int *com;
    com=Complementoa2(l);
    printf("\nEl Complementoa2 del binario es:");
    for(x=0;x<=32;x++){
        printf("%d",com[x]);
    }
    // Operación Bin2Dec
    int dec;
    dec= Bin2Dec(l);
    printf("\nEl binario convertido en decimal es:%d",dec);
    // Operación esBin
    int esB;
    esB = esBin(l);
    printf("%d",esB);

}