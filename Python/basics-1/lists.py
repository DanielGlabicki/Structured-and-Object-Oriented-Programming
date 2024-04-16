#!/usr/bin/python
# -*- coding: utf-8 -*-

#
# TEMAT: Listy
#
# -----------------------------------------------------------------------------

from typing import List, Any, Optional


def is_element_on_list(lst: List[Any], e: Any) -> bool:
    """Sprawdź, czy obiekt `e` znajduje się na liście `lst`.

    Przykład: is_elem_in_list([1, 2], 1) = True, is_elem_in_list([1, 2], False) = False

    :param lst: lista
    :param e: element, którego występowanie jest sprawdzane
    :return: True jeśli obiekt `e` występuje na liście `lst`, inaczej False
    """
    # return True if e in lst else False
    return e in lst
    # pass


def element_xor(lst: List[Any], e1: Any, e2: Any) -> bool:
    """Sprawdź, czy obiekt `e1` znajduje się na liście `lst` ORAZ obiekt `e2`
    NIE znajduje się na liście `lst`.

    Przykład: elem_xor([1, 2], 1, 3) = True, is_elem_in_list([1, 2], 1, 2) = False

    :param lst: lista
    :param e1: element, którego występowanie jest sprawdzane
    :param e2: element, którego NIEwystępowanie jest sprawdzane
    :return: True jeśli obiekt `e1` znajduje się na liście `lst` ORAZ obiekt `e2`
        NIE znajduje się na liście `lst`, inaczej False
    """
    return (e1 in lst) and not (e2 in lst)
    # pass


def print_every_second_elem(lst: List[str]) -> None:
    """Wypisz elementy listy o indeksach parzystych (wraz z tymi indeksami).

    W implementacji użyj `continue`.

    Przykład: print_every_second_elem(['abc', 'pqr', 'xyz'])
        0 -> abc
        2 -> xyz

    :param lst: lista łańcuchów znaków
    """
    for i in range (0, len(lst)):
        if i % 2 == 0:
            continue
        print(i, ' -> ', lst[i])
    # pass


def arg_condition(arg: Optional[List[Any]]) -> bool:
    """ Sprawdź, czy argument jest listą zawierającą więcej niż 2 elementy LUB
    czy argument ma wartość None.

    W implementacji użyj tylko jednej instrukcji (`return`)!
    W wyrażeniu logicznym skorzystaj z operatora OR oraz zastosuj
    mechanizm "short-circuting".

    Przykład: arg_cond_1(None) = True, arg_cond_1([1, 2]) = False,
        arg_cond_1([1, 2, 3]) = True

    :param arg: argument (lista lub wartość None)
    :return: True jeśli argument jest listą zawierającą więcej niż 2 elementy LUB
        jeśli argument ma wartość None, inaczej False
    """
    # return True if (arg == None or len(arg) > 2) else False
    return arg is None or len(arg) > 2
    # pass


def list_condition_1(lst: List[int]) -> bool:
    """Sprawdź, czy lista przekazana jako argument zawiera co najmniej 2 elementy
    ORAZ czy drugi element listy to 5.

    W implementacji użyj tylko jednej instrukcji (`return`)!

    :param lst: lista liczb całkowitych
    :return: (zob. opis)
    """
    return len(lst) >= 2 and lst[1] == 5
    # pass


def list_condition_2(lst: List[int]) -> bool:
    """Sprawdź, czy lista przekazana jako argument zawiera od 2 do 4 elementów
    ORAZ czy przedostatni element listy to 3.

    W implementacji użyj tylko jednej instrukcji (`return`)!

    :param lst: lista liczb całkowitych
    :return: (zob. opis)
    """
    return 2 <= len(lst) <= 4 and lst[-2] == 3
    # pass


def remove_first_three_elements(lst: List[Any]) -> None:
    """Usuń z listy do trzech pierwszych elementów (jeśli istnieją).

    Funkcja powinna modyfikować listę przekazaną jako argument.
    W implementacji użyj slice'ingu.

    :param lst: lista elementów dowolnego typu
    """
    # if len(lst) < 4:
    #     del lst[:]
    # else:
    #     lst[:len(lst) - 3] = lst[3:]
    #     del len[-3:]
    lst[:3] = []
    # pass


def replace_last_two_elements(lst: List[int]) -> List[int]:
    """Jeśli lista posiada co najmniej dwa elementy, zastąp dwa ostatnie
    elementy pojedynczym elementem 9.

    W implementacji użyj slice'ingu.

    NIE modyfikuj listy wejściowej!

    :param lst: lista liczb całkowitych
    :return: lista liczb po ewentualnej zamianie
    """
    lst2 = lst[:]
    if len(lst2) >= 2:
        lst2[-2:] = [9]
    return lst2
    # pass


def merge_ends(lst: Optional[List[Any]] = None) -> List[Any]:
    """Sklej końce listy.

    Zawartość listy wynikowej zależy od liczby elementów w liście przekazanej
    jako argument:
        (a) jeśli co najmniej 4 – lista złożona z pierwszych dwóch i ostatnich dwóch elementów,
        (b) jeśli 1-3 – lista złożna z 2 płytkich kopii pierwszego elementu,
        (c) jeśli 0 (lub None) - pusta lista

    W implementacji NIE używaj pętli `for`.

    NIE modyfikuj listy wejściowej!

    :param lst: lista, której końce mają zostać scalone (domyślnie None)
    :return: lista wynikowa, zawierająca elementy zgodnie ze schematem w opisie
    """
    if lst is None or len(lst) == 0:
        lst2 =[]
    elif 1 <= len(lst) <= 3:
        lst2 = [lst[0], lst[0]]
    else:
        lst2 = [lst[0], lst[1], lst[-2], lst[-1]]
    return lst2

    # pass


def remove_element_if_exists(lst: List[Any], e: Any) -> List[Any]:
    """Zwróć listę po usunięciu pierwszego wystąpienia elementu `e`.

    NIE modyfikuj listy wejściowej!

     W implementacji skorzystaj z metody remove(x) - upewnij się wcześniej, że
     element `x` w ogóle występuje w liście!

    :param lst: lista elementów
    :param e: element, którego pierwsze wystąpienie powinno zostać usunięte
        z listy wejściowej
    :return: lista powstała przez usunięcie z listy wejściowej pierwszego
        wystąpienia elementu `e`
    """
    lst2 = lst[:]
    if e in lst2:
        lst2.remove(e)
    return lst2
    # pass


# [OPT]
def is_palindrome(s: str) -> bool:
    """Sprawdź, czy łańcuch znaków jest palindromem.

    W implementacji użyj slice'ingu.

    :param s: łańcuch znaków
    :return: wartość logiczna Prawda, jeśli łańcuch znaków jest palindromem,
        inaczej wartość logiczna Fałsz
    """
    return s == s[::-1]
    # pass
