# Author : SV
# date 2020/10/12, V1
# date 2015/10/12, V0

# Bien mettre le chemin du rÃ©pertoire de travail (Session -> Set Working Directory -> To Source File Location)
setwd("~/Documents/M1/Optim_problem/verel_tp")

############################
# recherche alÃ©atoire

# lit les donnÃ©es des recherches alÃ©atoires
df.rs <- read.table("./cmake-build-release/result_recuit.csv", header = TRUE, sep = ",")

# si besoin renommer les 2 colonnes :
names(df.rs) <- c("id", "nbeval", "fitness")

# vÃ©rification du fichier: affiche les premiÃ¨res lignes
head(df.rs)

max(df.rs$fitness)

# histogramme pour un nombre d'Ã©valuation 10000 : nota, la distribution n'est pas gaussienne
hist(df.rs[df.rs$nbeval == 1e+07,]$fitness)

# calcul de la moyenne
mean(df.rs[df.rs$nbeval == 1e+07,]$fitness)

# rÃ©sumÃ© des principales statistiques
summary(df.rs[df.rs$nbeval == 1e+07,]$fitness)

# nuage de points des fitness obtenues en fonction du nombre d'Ã©valuation
plot(fitness ~ nbeval, data = df.rs)

## Remarque : sans la librairie doBy 

# split des donnÃ©es selon les valeur en ligne (obtient alors une liste)
l <- split(df.rs$fitness, factor(df.rs$nbeval))

# boite a moustache (boxplot) de la fitness en fonction du nombre d'Ã©valuation (attention echelle non respectÃ©e en abscisse)
boxplot(l)

# calcul des moyennes (nota: R est un langage fonctionnel)
l.mean <- lapply(l, FUN = mean)

# et le plot fitness vs. moyenne
plot(names(l.mean), unlist(l.mean))


############################
# marche alÃ©atoire

# lit les donnÃ©es de la marche alÃ©atoire
df.rw <- read.table("rw.csv", header = TRUE, sep = " ")

# vÃ©rification du fichier: affiche les premiÃ¨res lignes
head(df.rw)

# histogramme des fitness : nota, la distribution n'est pas gaussienne
hist(df.rw$fitness)

# fitness en fonction du nombre d'itÃ©ration. Nota : les variations sont "alÃ©atoires" mais bornÃ©es.
plot(df.rw$fitness, type = "l")

# calcul de la fonction d'autocorrelation : beaucoup de correlation entre les fitness des solutions voisines
cors <- acf(df.rw$fitness)

# le premier coefficient d'autocorrelation est trÃ¨s proche de 1:
print(cors[1])

# plus le coefficient est proche de 1, 
# plus le "paysage" du problÃ¨me est "smooth", 
# et, selon cet indicateur, plus facile Ã  optimiser localement 