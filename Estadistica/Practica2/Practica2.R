# Ejercicio 1
juegos <- read.table("Juegos.dat")
attach(juegos)
table(Fecha)
fechas <- names(table(Fecha))
fechas
ni <- as.numeric(table(Fecha))
ni
fi <- ni / length(Fecha)
Ni <- cumsum(ni)
Fi <- cumsum(fi)
tabla_fechas <- data.frame(fechas, ni, fi, Ni, Fi)
tabla_fechas

# Ejercicio 2 se hace en pizarra

# Ejercicio 3
str(VentasEU)
datos <- VentasEU[1:3]
datos
N <- length(datos)
m1 <- sum(datos) / N
m1
v1 <- sum((datos - m1)^2) / N
v1
m2 <- mean(datos)
m2
v2 <- var(datos) * (N - 1) / N
v2
summary(VentasEU)
N <- length(VentasEU)
c(mean(VentasEU), sum(VentasEU) / N)
c(var(VentasEU) * (N - 1) / N, sum((VentasEU - mean(VentasEU))^2) / N)
n_i <- table(VentasEU)
n_i
modaVentasEU <- sort(n_i)[length(n_i)]
modaVentasEU
summary(VentasEU)
mean(VentasEU)
median(VentasEU)
table(VentasEU)
h <- hist(VentasEU)
str(h)
datos2 <- VentasEU[VentasEU <= 1]
a <- hist(datos2)
datos2_int <- cut(datos2, breaks = a$breaks, include.lowest = TRUE)
valores <- names(table(datos2_int))
ni_datos2_int <- as.numeric(table(datos2_int))
fi_datos2_int <- ni_datos2_int / length(datos2_int)
Ni_datos2_int <- cumsum(ni_datos2_int)
Fi_datos2_int <- cumsum(fi_datos2_int)
tabla_datos2_int <- data.frame(valores, ni_datos2_int, fi_datos2_int, Ni_datos2_int, Fi_datos2_int)
tabla_datos2_int
marcas <- a$mids
frec <- a$counts / sum(a$counts)
m_clases <- sum(marcas * frec)
m_clases
v_clases <- sum((marcas - m_clases)^2 * frec)
v_clases


# Ejercicio 4
min(VentasEEUU)
max(VentasEEUU)
VentasEEUU_filt <- VentasEEUU[VentasEEUU <= 10]
hist(VentasEEUU_filt, breaks = c(0, 0.1, 0.5, 1, 5, 20), right = FALSE)
hist(VentasEEUU[VentasEEUU <= 10], breaks = c(0, 0.1, 0.5, 1, 5, 20), right = FALSE)
VentasEEUU_int2 <- VentasEEUU[VentasEEUU <= 1]
hist(VentasEEUU_int2, breaks = c(0, 0.1, 0.3, 0.7, 1), include.lowest = TRUE)
hist(VentasEEUU[VentasEEUU <= 1], breaks = c(0, 0.1, 0.3, 0.7, 1), include.lowest = TRUE)


# Ejercicio 5
nVentasJP <- hist(VentasJP[VentasJP <= 1])
VentasJP_int <- cut(VentasJP[VentasJP <= 1], breaks = nVentasJP$breaks, include.lowest = TRUE)
barplot(table(VentasJP_int))

# Ejercicio 6
VentasOtros_tipificados <- (VentasOtros - mean(VentasOtros)) / sd(VentasOtros)
hist(VentasOtros)
hist(VentasOtros_tipificados)
VentasOtros_nuevos <- VentasOtros_tipificados * 0.2 + 0.5
mean(VentasOtros_nuevos)
hist(VentasOtros_nuevos)
