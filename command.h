/* File: command.h */
/* Definisi command: Seluruh fungsi dan prosedur yang digunakan saat menggunakan
                     command tertentu dalam program utama*/

#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "boolean.h"
#include "map.h"
#include "listsirkuler.h"
#include "queue.h"
#include "listvillage.h"
#include "stackpoint.h"

void Move(MATRIKS *Map, Unit *CurrUnit, List *ListUnit, Stack *StackPoint);
/*I.S. Map terdefinisi Map yang sudah di create oleh CreateMap
       CurrUnit Terdefinisi yang ada dalam ListUnit dan Selected Unit di main
       ListUnit terdefinisi tidak kosong minimal berisi CurrUnit
       StackUnit sembarang
  F.S.
       Menampilkan Map dengan # sebagai penanda tujuan Move CurrUnit yang mungkin
       Map diupdate sesuai hasil MOVE CurrUnit
       CurrUnit Terupdate Movementpointnya seletah Move
       listUnit terupdate dengan CurrUnit dalam list tsp terupdate
       StackPoint di push point akhir CurrUnit*/

void Undo(MATRIKS *Map, Unit *CurrUnit, List *ListUnit, Stack *StackPoint);
/*I.S. Map terdefinisi Map yang sudah di create oleh CreateMap
       CurrUnit Terdefinisi yang ada dalam ListUnit dan Selected Unit di main
       ListUnit terdefinisi tidak kosong minimal berisi CurrUnit
       StackUnit sembarang
  F.S. Bila StackPoint kosong maka Undo Gagal
       Map diupdate sesuai hasil UNDO CurrUnit
       CurrUnit Terupdate positionnya kembali ke kondisi sebelumnya
       listUnit terupdate dengan CurrUnit dalam list tsp terupdate
       StackPoint di pop point akhir CurrUnit*/

void Change_Unit(Unit *CurrUnit, List ListUnit);
/*I.S. CurrUnit Terdefinisi Selected unit di main
       ListUnit Terdefinisi tidak kosong minimal berisi CurrUnit
  F.S. Menampilkan Unit yang dapat dipilih di dalam ListUnit
       CurrUnit Berubah bila memilih Unit yang ada di ListUnit*/

void Recruit(MATRIKS *Map, List ListOfUnit, List *ListUnit, Player *P);
/*I.S. Map terdefinisi map yang sudah di create oleh CreateMap
       ListOfUnit terdefinisi merupakan List Seluruh Unit yang ada di program
       ListUnit terdefinisi ListUnit Player P
       P sembarang
  F.S. Menampilkan pada petak mana dapat merekrut Unit
       Map terupdate sesuai hasil RECRUIT
       ListUnit di Insert Unit yang sudah di rekrut
       Gold(P) berkurang sesuai Biaya unit Income dan Upkeep juga*/
void Attack(MATRIKS *Map, Unit *CurrUnit, List *ListUnitP1, List *ListUnitP2, Player *P1, Player *P2, );
/*I.S. Map terdefinisi map yang sudah di create oleh CreateMap
       CurrUnit terdefinisi SelectedUnit
       ListUnitP1 dan ListUnitP2 merupakan List Unit Masing2 Player
       P1 dan P2 merupakan masing2 player
  F.S. map Terupdate bila ada unit yang mati
       CurrUnit canatack diupdate menjadi false bila berhasil dan health terudate
       ListUnitP1 dan ListUnitP2 diupdate health unit yang terlibat
       P1 dan P2 terupdate income dan Upkeepnya bila ada unit yang mati*/
void Map(MATRIKS Map, Unit CurrUnit);
/*I.S. Map terdefinisi Map yang di CreateMap
      CurrUnit merupakan Unit skrg
  F.S. Menampilkan Map dengan CurrUnit Berwarna Hijau*/
void Info(MATRIKS Map, List ListUnitP1, List ListUnitP2);
/*I.S. map terdefinisi
       ListUnitP1 dan ListUnitP2 merupakan list unit masing2 player
  F.S. Menampilkan Info dari building hingga unit suatu petak*/

#endif
