#Práctica 3 resuelta, curso 2021/2022

#Ejercicio 1
juegos<-read.table("Juegos.dat")
attach(juegos)
str(juegos)
hist(VentasEU[VentasEU>0.1 & VentasEU<1])
hist(VentasEEUU[VentasEEUU>0.1 & VentasEEUU<1])
hist(VentasOtros[VentasOtros>0.1 & VentasOtros<1])
hist(as.numeric(Fecha))
#a)
summary(VentasEEUU)
quantile(VentasEEUU,c(0.25,0.5,0.75))
boxplot(VentasEEUU)

#b)
datos<-VentasEEUU[VentasEEUU>0.1 & VentasEEUU<1]

#c)
deciles<-quantile(datos,seq(0.1,0.9,0.1))
cuartiles<-quantile(datos,c(0.25,0.5,0.75))

#d)
Q1<-as.numeric(quantile(datos,0.25))
Q3<-as.numeric(quantile(datos,0.75))
RIC<-Q3-Q1

#Alternativamente, podemos utilizar las variables creadas en el apartado c)
#Q1<-as.numeric(cuartiles[1])
#Q3<-as.numeric(cuartiles[3])

#e)
o1<-Q1-1.5*RIC
o1
o2<-Q3+1.5*RIC
o2

#datos atípicos los datos < o1 y los datos > o2
datos[datos<o1]
datos[datos>o2]

#todos los datos atípicos juntos
datos_atipicos<-datos[datos<o1 | datos>o2]

#f)
boxplot(datos)
hist(datos)

#El rectángulo tiene como techo el tercer cuartil y como suelo el primer cuartil. La línea gruesa que atraviesa el rectángulo horizontalmente es la mediana. La línea vertical traceada indica hasta dónde llegan los datos no atípicos. Cada dato atípico viene indicado con un círculo.

#g)
#Tenemos que partir los datos de la siguiente manera
#
#       20%        60%       20%
#       ----|----------------|----
#         cat1             cat3

cat1<-quantile(datos,0.2)
cat1
cat3<-quantile(datos,0.8)
cat3

datos_cat1<-datos[datos<=cat1]
datos_cat2<-datos[datos>cat1 & datos<cat3]
datos_cat3<-datos[datos>=cat3]

length(datos_cat1)/length(datos)

#Se obtiene un valor un poco por encima del 20% porque muchos de los valores de datos_cat1 son iguales a cat1.

#Ejercicio 2

datos2<-VentasJP[VentasJP>0.5 & VentasJP<1]
a<-hist(datos2)
mean(datos2)
var(datos2)
summary(datos2)

datos2_intervalos<-cut(datos2,breaks=a$breaks,include.lowest=TRUE)

intervalos<-names(table(datos2_intervalos))	#guardamos los intervalos
n_i<-as.numeric(table(datos2_intervalos))	#frecuencia absoluta
f_i<-n_i/length(datos2_intervalos) #frecuencia relativa
N_i<-cumsum(n_i)	#frecuencia absoluta acumulada
F_i<-cumsum(f_i)	#frecuencia relativa acumulada

tabla_estadistica<-data.frame(intervalos,n_i,N_i,f_i,F_i)
tabla_estadistica

#También se puede usar la función cbind
#tabla_estadistica<-cbind(intervalos,n_i,N_i,f_i,F_i)

m<-median(datos2)
Q<-quantile(datos2,c(0.25,0.75))
#También podemos obtener los cuartiles en dos variables independientes
#Q1<-quantile(datos2,0.25)
#Q3<-quantile(datos2,0.75)

RIC<-as.numeric(Q[2])-as.numeric(Q[1])
#atípicos
adatos2<-datos2[datos2<as.numeric(Q[1])-1.5*RIC | datos2>as.numeric(Q[2])+1.5*RIC]

boxplot(datos2)

