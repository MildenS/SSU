/*
	remove if:
удаление по предикату, которое работает не совсем как удаление. Т.е. она (функция) сдвигает в начало элементы, которые не должны быть удалены,
затирая или перемещая в конец "ненужные", возвращая в итоге итератор на начало тех элементов, которые должны быть удалены. 
Эта функция работает именно так, потому что она не может менять размер контейнера.
Принмает два итератора (начало и конец) и предикат. 
Применима ко всем контейнерам stl (строки, векторы, list), кроме set (потому что у него нельзя элементы двигать)
до С++11 использовала оператор присваивания?(copy assignment), после стала использовать move-семантику (move assignment)
С C++20 remove_if получил модификатор constexpr, т.е. возращаемое значение является константой времени компиляции (звучит странно, поэтому, порыскав ещё по интернету,
я нашёл информацию, что для функций constexpr может делать их возвращаемое значение константой времени компиляции, а может и не делать, если не получается)
*/

/*
	erase_if:
"Старший брат remove_if, потому что умеет удалять элементы, меняя размер коллекции. Под капотом имеет свою младшую версию erase в связке с remove_if (но это не точно)
Как и remove_if, начиная с С++20, является constexpr функцией, но в отличии от своего младшего брата он появился только в 20-м стандарте
Работает со всеми stl контейнерами (даже с set). В отличие от remove_if принимает не пару итератор (начало и конец) с предикатом, а ссылку на контейнер и предикат.
Возращает кол-во удалённых элементов(?).
Стоит отметить, что и erase_if и remove_if используют унарные предикаты в качестве критерия удаления элемента
(так как фича свежая, то информации о ней мало, на cppreference у каждого контейнера вообще своё описание этой функции, следовательно у неё довольно много версий,
но шаблон, вроде как, один)
*/