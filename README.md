# 2-as laboratorinis darbas (14 variantas)

## Varianto sąlyga
Rasti N valdovių išdėstymą M trikampėje lentoje, kad jos viena kitos nekirstų.

Maksimalus valdovių skaičius N-trikampėj lentoje: floor((2*N + 1) / 3).

Informacijos šaltinis: <http://acmgnyr.org/year2006/g.pdf>.

## Algoritmo aprašymas

Naudojamas perrinkimo (backtracking) metodas.

Trys atakos kryptys trikampėje lentoje:
- ta pati eilutė
- tas pats stulpelis
- tas pats skirtumas eilutė - stulpelis (įstrižainė)

Valdovė dedama tik į laisvą langelį — kai visos trys kryptys neužimtos.
Jei einamas kelias neduoda sprendinio, grįžtama atgal ir bandoma kita vieta.
Prieš pradedant backtrack tikrinama ar M neviršija maksimalaus skaičiaus pagal formulę —
jei viršija, sprendinys neieškomas.

## Programos naudojimas
# Paleidimas iš failo

```
$ make.exe duomenys.txt
```

Failo formatas - kiekviena eilutė yra vienas testas

```
N M
N M
...
```
# Paleidimas per parametrus

```
$ main.exe -n 10 -m 7 -timeout 5000
```

# Timeout
Jei nurodytas `-timeout milisekundės`, programa sustoja viršijus laiką ir išveda kiek backtrack mazgų buvo aplankyta. Tikslių procentų apskaičiuoti neįmanoma — backtrack medis nėra lygus, todėl nežinoma kiek šakų liko.
