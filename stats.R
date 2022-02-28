library(readr)
result <- read_csv("Development/ulco/M1/Optimisation_verel/TP1/cmake-build-release/result.csv")
View(result)

fitness <- result[result$`Max try` == 10000,]
fitness2 <- result[result$`Max try` == 1000,]
summary(fitness$fitness)
mean(fitness$fitness)
min(fitness$fitness)
max(fitness$fitness)

hist(fitness$fitness)
boxplot(fitness$fitness, fitness2$fitness)
plot(`Max try`  ~ fitness, data=result)
cor(fitness$fitness, fitness$`Max try`)
