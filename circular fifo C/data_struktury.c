/*
 * data_struktury.c
 *
 *  Created on: 14. 12. 2016
 *      Author: student
 */
#include <stdio.h>
#include "stdint.h"
#include "DSP2833x_Device.h"
#include "math.h"
#include <assert.h>
#include "data_struktury.h"
#include "global_variables.h"

/*
*FIFO (KRUHOVE) POLE PRO VYPOCET DELTA_OMEGA (diference otacek)
* FLOATING POINT FORMAT
*/
//funkce pro pripravu pole
void fifo_init(fifo_pole *struktura_s_polem, int16 zadana_velikost, float32 *konkretni_pole, int16 poc_index){
	struktura_s_polem->data = konkretni_pole; //pointer na konkretni pole
	struktura_s_polem->index= 0; //aktualni index fifo pole
	struktura_s_polem->velikost = zadana_velikost;
}

/*
 * Nejdrive je potreba provadet cteni, aby se ziskala nejstarsi hodnota v poli,
 * nasledne funkce fifo_prepis_a_posun provede nejdrive prepis nejstarsiho prvku a pak posun
 * indexu o krok dal
  */

//funkce pro cteni z pole na aktualnim indexu
float32 fifo_cti(fifo_pole *pole){ //jen cte z indexu, nemeni index, ani nic nemaze
	return pole->data[pole->index];
}

//funkce ktera do fifo pole zapise a pak rotuje jeho index
void fifo_prepis_a_posun(fifo_pole *pole, float32 zapisovana_hodnota){ //nejdriv prepis na indexu a pak posun indexu o 1
	pole->data[pole->index] = zapisovana_hodnota;
	if ((pole->index) > ((pole->velikost) - 2))
	{
		pole->index = 0;
	}
	else{
		pole->index = (pole->index + 1);
	}
}
/*
 *
 */
/*KRUHOVE POLE VE FIXED POINT FORMAT - Q15 (int16) */
void fifo_init_int(fifo_pole_int *struktura_s_polem, int16 zadana_velikost, int16 *konkretni_pole, int16 poc_index){
	struktura_s_polem->data = konkretni_pole; //pointer na konkretni pole
	struktura_s_polem->index= 0; //aktualni index fifo pole
	struktura_s_polem->velikost = zadana_velikost;
}
int16 fifo_cti_int(fifo_pole_int *pole){ //jen cte z indexu, nemeni index, ani nic nemaze
	return pole->data[pole->index];
}
void fifo_prepis_a_posun_int(fifo_pole_int *pole, int16 zapisovana_hodnota){ //nejdriv prepis na indexu a pak posun indexu o 1
	pole->data[pole->index] = zapisovana_hodnota;
	if ((pole->index) > ((pole->velikost) - 2))
	{
		pole->index = 0;
	}
	else{
		pole->index = (pole->index + 1);
	}
}



void proved_klouzavy_prumer(fifo_pole *pole, float32 *aktualni_hodnota, float32 novy_vzorek, float32 lomeno_velikost){ //implementace filtru pres klouzavy prumer
	*aktualni_hodnota -= (fifo_cti(pole)) * lomeno_velikost; //odebrani nejstarsiho vzorku s dano vahou (1/velikost)
	*aktualni_hodnota += novy_vzorek * lomeno_velikost;  //pridani noveho vzorku s danou vahou (1/velikost)
	fifo_prepis_a_posun(pole, novy_vzorek); // rotace v poli
}



