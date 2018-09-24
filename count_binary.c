count_cell = 0
sum = 0
temp_register

for (count_cell = 0; count_cell < 1024; count_cell++){
	bool lsb = read_lsb(count_cell)

	if (lsb == 0) {
		sum+=read_value_cell(count_cell)
	} else {
		temp_register=read_value_cell(count_cell)
		bool pari = read_lbs(count_cell)
		// divisibile per 4 vuol dire divisibile per 2 e divisibile per 2 avendo diviso per 2
		bool div_quattro = read_lsb(switch_right(temp_register))

		if (pari && div_quattro){
			sum -= read_value_cell(count_cell)
		} else {
			// moltiplicazione per 4 spostando a sinistra di 2 bit il valore
			sum += switch_left(switch_left(read_value_cell(count_cell)))
		}


	}
}