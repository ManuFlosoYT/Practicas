# Ejercicio 1
peso <- c(72, 74, 72, 76, 72, 73)
nota <- c(4, 5, 7, 8, 4, 5)
genero <- rep(c("Mujer", "Hombre"), c(4, 2))

consola <- scan("P1_Ej1.txt", what = character(), sep = ",", strip.white = TRUE)
str(consola)

tipos <- c("Linux", "Windows", "MacOS", "SunSolaris", "Unix", "Embedded", "Otro")
freq <- c(138, 123, 6, 9, 9, 6, 9)
SO <- rep(tipos, freq)
table(SO)[0:7]

# Ejercicio 2
personas <- data.frame(peso, nota, genero)
str(personas)


# Ejercicio 3
peso_txt <- scan("pesos.txt", what = numeric(), sep = " ", strip.white = TRUE)
leng_txt <- scan("lenguajes.txt", what = character(), sep = "\n", strip.white = TRUE)
juegos <- read.table("Juegos.dat")

# Ejercicio 4
str(juegos)
n_i.Genero <- table(Genero) # frecuencias absolutas
f_i.Genero <- n_i.Genero / length(Genero) # frecuencias relativas
tabla.Genero <- data.frame(n_i.Genero, f_i.Genero)

n_i.Fecha <- table(Fecha) # frecuencias absolutas
f_i.Fecha <- n_i.Fecha / length(Fecha) # frecuencias relativas
tabla.Fecha <- data.frame(n_i.Fecha, f_i.Fecha)

n_i.Plataforma <- table(Plataforma) # frecuencias absolutas
f_i.Plataforma <- n_i.Plataforma / length(Plataforma) # frecuencias relativas
tabla.Plataforma <- data.frame(n_i.Plataforma, f_i.Plataforma)

barplot(n_i.Genero)
barplot(n_i.Fecha)
barplot(n_i.Plataforma)

pie(f_i.Genero)
pie(f_i.Fecha)
pie(f_i.Plataforma)

f_i.Genero[0:12] * 360
f_i.Fecha[0:32] * 360
f_i.Plataforma[0:19] * 360

# Ejercicio 5
internet <- c(65.9, 72.3, 70, 30.9, 84.2, 65.3, 64.8, 71.8, 68.3, 83.5, 69.3, 45.9, 85.6, 55.5, 59.3, 51.7, 61.4, 59.2, 78.7, 49.4, 52, 41.8, 76.4, 59, 8.2)
table(internet)
min(internet)
max(internet)
internet_intervalos1 <- cut(internet, breaks = seq(0, 90, 10))
internet_intervalos1
internet_intervalos2 <- cut(internet, breaks = c(0, 30, 50, 60, 70, 90), right = FALSE)
internet_intervalos2
internet_intervalos3 <- cut(internet, breaks = c(0, 20, 50, 70, 100), right = TRUE)
internet_intervalos3
n_i.internet_intervalos1 <- table(internet_intervalos1)
N_i.internet_intervalos1 <- cumsum(n_i.internet_intervalos1)
N <- length(internet_intervalos1)
f_i.internet_intervalos1 <- n_i.internet_intervalos1 / N
F_i.internet_intervalos1 <- cumsum(f_i.internet_intervalos1)
n_i.internet_intervalos2 <- table(internet_intervalos2)
N_i.internet_intervalos2 <- cumsum(n_i.internet_intervalos2)
N <- length(internet_intervalos2)
f_i.internet_intervalos2 <- n_i.internet_intervalos2 / N
n_i.internet_intervalos3 <- table(internet_intervalos3)
N_i.internet_intervalos3 <- cumsum(n_i.internet_intervalos3)
N <- length(internet_intervalos3)
f_i.internet_intervalos3 <- n_i.internet_intervalos3 / N
barplot(n_i.internet_intervalos1)
pie(n_i.internet_intervalos1)
barplot(n_i.internet_intervalos2)
pie(n_i.internet_intervalos2)
barplot(n_i.internet_intervalos3)
pie(n_i.internet_intervalos3)
internet_seleccion <- internet[internet >= 65 & internet < 80]
sort(internet_seleccion)
sort(internet_seleccion, decreasing = TRUE)

# Ejercicio 6
VentasEU_intervalos1 <- cut(VentasEU, breaks = seq(0, 30, 2))
sum(table(VentasEU_intervalos1))
length(VentasEU)
VentasEU_intervalos1 <- cut(VentasEU, breaks = seq(0, 30, 2), include.lowest = TRUE)
sum(table(VentasEU_intervalos1))
VentasEU_intervalos2 <- cut(VentasEU, breaks = c(0, 0.1, 0.2, 0.5, 1, 10, 30), right = TRUE)
VentasEU_intervalos3 <- cut(VentasEU, breaks = c(0, 0.1, 0.2, 0.5, 1, 10, 30), right = TRUE)
n_i.VentasEU_intervalos1 <- table(VentasEU_intervalos1)
N <- length(VentasEU_intervalos1)
f_i.VentasEU_intervalos1 <- table(VentasEU_intervalos1) / N
N_i.VentasEU_intervalos1 <- cumsum(n_i.VentasEU_intervalos1)
F_i.VentasEU_intervalos1 <- cumsum(f_i.VentasEU_intervalos1)
n_i.VentasEU_intervalos2 <- table(VentasEU_intervalos2)
N <- length(VentasEU_intervalos2)
f_i.VentasEU_intervalos2 <- table(VentasEU_intervalos2) / N
N_i.VentasEU_intervalos2 <- cumsum(n_i.VentasEU_intervalos2)
F_i.VentasEU_intervalos2 <- cumsum(f_i.VentasEU_intervalos2)
n_i.VentasEU_intervalos3 <- table(VentasEU_intervalos3)
N <- length(VentasEU_intervalos3)
f_i.VentasEU_intervalos3 <- table(VentasEU_intervalos3) / N
N_i.VentasEU_intervalos3 <- cumsum(n_i.VentasEU_intervalos3)
F_i.VentasEU_intervalos3 <- cumsum(f_i.VentasEU_intervalos3)
barplot(n_i.VentasEU_intervalos1)
pie(n_i.VentasEU_intervalos1)
barplot(n_i.VentasEU_intervalos2)
pie(n_i.VentasEU_intervalos2)
barplot(n_i.VentasEU_intervalos3)
pie(n_i.VentasEU_intervalos3)
hist(VentasEU, breaks = seq(0, 30, 2), include.lowest = TRUE)
hist(VentasEU, breaks = c(0, 0.1, 0.2, 0.5, 1, 10, 30), right = FALSE)
hist(VentasEU, breaks = c(0, 0.1, 0.2, 0.5, 1, 10, 30), include.lowest = TRUE)
VentasEU_seleccion <- VentasEU[VentasEU >= 5]
