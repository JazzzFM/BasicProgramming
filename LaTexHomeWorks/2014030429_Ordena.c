#define M 20
#define Telemento float


void MezclaLista(Telemento a[], int Izq, int Centro, int Der);
void MergeSort(Telemento a[], int Izq, int Der)
{
	int Centro;
	if (Izq < Der)
	{
		Centro = (Izq+Der) / 2;
		MergeSort(a, Izq, Centro);
		MergeSort(a, Centro + 1, Der);
		MezclaLista(a, Izq, Centro, Der);
	}
}

void MezclaLista(Telemento a[], int Izq, int Centro, int Der)
{
	Telemento Temporal[M];
	int i, j, k;
	i = k = Izq;
	j = Centro + 1;

/* bucle de mezcla, utiliza Temporal[] como array auxiliar*/

	while (i <= Centro && j <= Der)
	{
		if (a[i] <= a[j])
		Temporal[k++] = a[i++];
		else
		Temporal[k++] = a[j++];
	}
/* bucles para mover elementos que quedan de sublistas */

	while (i <= Centro)
	Temporal[k++] = a[i++];
	
	while (j <= Der)
	Temporal[k++] = a[j++];
/* Copia de elementos de Temporal[] al array a[] */
	
	for (k = Izq; k <= Der; k++)
	a[k] = Temporal[k];
}

