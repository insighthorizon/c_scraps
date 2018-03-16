/*
 * data_struktury.h
 *
 *  Created on: 14. 12. 2016
 *      Author: student
 */

#ifndef SRC_DATA_STRUKTURY_H_
#define SRC_DATA_STRUKTURY_H_

//veci pro praci s ukladanymi vzorky merenych hodnot (reseni poli) -vypocet rychlosti, filtry
//kruhove pole FIFO buffer - pro praci s polem vzorku

typedef struct
{
	float32 *data;
	int16 index;
	int16 velikost;
} fifo_pole;

typedef struct
{
	int16 *data;
	int16 index;
	int16 velikost;
} fifo_pole_int;

void fifo_init(fifo_pole *struktura_s_polem, int16 zadana_velikost, float32 *konkretni_pole, int16 poc_index);
float32 fifo_cti(fifo_pole *pole);
void fifo_prepis_a_posun(fifo_pole *pole, float32 zapisovana_hodnota);

void fifo_init_int(fifo_pole_int *struktura_s_polem, int16 zadana_velikost, int16 *konkretni_pole, int16 poc_index);
int16 fifo_cti_int(fifo_pole_int *pole);
void fifo_prepis_a_posun_int(fifo_pole_int *pole, int16 zapisovana_hodnota);

void proved_klouzavy_prumer(fifo_pole *pole, float32 *aktualni_hodnota, float32 novy_vzorek, float32 lomeno_velikost);


#endif /* SRC_DATA_STRUKTURY_H_ */
