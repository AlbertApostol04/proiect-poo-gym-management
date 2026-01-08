# Gestionare sală de fitness (abonamente, antrenori, plăți)  - Proiect POO

Aplicatie in C++(consola) pentru a gestiona clienții unei săli de fitness: creare clienți, atașare abonamente, gestionare antrenori, procesare plăți(cash sau card), check-in(pentru clienți și pentru antrenori).



## Funcționalități principale

- Meniu interactiv pentru:
  - clienți:adăugare, listare, căutare după ID, atașare abonament, check-in
  - antrenori:listare, afișare clienți alocați,check-in antrenor
  - 
- Abonamente:
  -AbonamentCuIntrari(8 intrări)
  - AbonamentPerioada(abonament cu 1/7/14/28 zile)
  - AbonamentCuAntrenor(ședinte + numele antrenorului alocat)
  **Toate abonamentele expiră după 30 de zile de la cumpărare!**

- Plăți :
  - PlataCash(rest sau sumă insuficientă->excepție)
  - PlataCard(validare card)



## Concepte POO folosite

- 2 ierarhii de clase:
  - Abonament(clasă abstractă)->derivate (polimorfism, virtual, override)
  - Plata(clasă abstractă)->derivate
   
- Upcast și downcast:
  - upcast:folosire prin pointer/referință la bază + apel virtual (checkIn())
  - downcast:dynamic_cast pentru acces la funcții specifice (AbonamentCuAntrenor)
    
- Excepții (std::exception, std::invalid_argument, std::runtime_error) si propagare
- STL:vector, map, algoritmi cu lambda (find_if și min_element)
- Template: Cutie<T>(exemplu: Cutie<int>,Cutie<std::string>)
  
- Design patterns:
  - Factory:FabricaPlati creează PlataCash/PlataCard în funcție de input
  - Strategy:comportamentul plății difera în funcție de tipul concret(PlataCash sau PlataCard)
 
## Structură proiect
- include/– headere(.h)
- src/ –implementări (.cpp)
- CMakeLists.txt –build
- README.md –descriere proiect





