/*
 * tileimage.cpp
 *
 *  Created on: 23/3/2016
 *      Author: Usuario
 */

#include "math.h"
#include "tileimage.h"
#include "tiledata.h"

TileImage::TileImage(tinyxml2::XMLElement * t)
{
	bmp = NULL;
	root_tileimage = t;
	printf("creado tileimage\n");
	parse();
	cargar_imagen();
}
TileImage::~TileImage()
{

}
void TileImage::draw(int x,int y)
{
	/*
	 * Dibuja la imagen completa en la posición x,y
	 */
	if (bmp != NULL)	al_draw_bitmap(bmp,y,x,0);
}
void TileImage::draw(int x,int y,int t)
{
	/*
	 * Dibuja el tile t en la posición x,y
	 */

}
void TileImage::parse()
{
	tinyxml2::XMLError 			eResult;
	tinyxml2::XMLElement 		* pElement_tmp;
	const char 					* szAttributeText;

	/*
	 * Se extraen todos los atributos del elemento map
	 */
	szAttributeText = NULL;
	szAttributeText = root_tileimage->Attribute("format");
	if (szAttributeText == NULL) {
		printf("format no encontrado\n");
	}else {
		format = szAttributeText;
		printf("format %s\n",format.c_str());
	}
	szAttributeText = NULL;
	szAttributeText = root_tileimage->Attribute("source");
	if (szAttributeText == NULL) {
		printf("source no encontrado\n");
	}else {
		source = szAttributeText;
		printf("source %s\n",source.c_str());
	}
	szAttributeText = NULL;
	szAttributeText = root_tileimage->Attribute("trans");
	if (szAttributeText == NULL) {
		printf("trans no encontrado\n");
	}else {
		trans = szAttributeText;
		printf("trans %s\n",trans.c_str());
	}
	eResult = root_tileimage->QueryIntAttribute("width", &width);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando width: %i\n", eResult);
	}else{
		printf("width %d\n",width);
	}
	eResult = root_tileimage->QueryIntAttribute("height", &height);
	if (eResult != tinyxml2::XML_SUCCESS)  {
		printf("Error cargando height: %i\n", eResult);
	}else{
		printf("height %d\n",height);
	}
	/*
	 * Creamos el elemento data si existe
	 */
	pElement_tmp = root_tileimage->FirstChildElement("data");
	if (pElement_tmp == NULL) {
		printf("no hay ningun elemento tiledata\n");
	} else {
		data = new TileData(pElement_tmp);
	}

}
void TileImage::cargar_imagen()
{
	ALLEGRO_PATH   				*path;
	int 						R,G,B,i;
	std::string::iterator		it; // The string iterator.
	std::string					string_tmp;

	/*
	* para crear path relativos y poder distribuir el programa y ejecutarlo
	* fuera del IDE
	*/

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_remove_path_component(path,-1);
	al_append_path_component(path, "resources");

	if (source != "") {
		al_set_path_filename(path, source.c_str());

		bmp = al_load_bitmap(al_path_cstr(path, '/'));
		if(bmp == NULL)
		{
			al_show_native_message_box(al_get_current_display(), "Ventana de error",
									   "error fatal", "Error al cargar resource bitmap",
									   NULL, ALLEGRO_MESSAGEBOX_ERROR);
			exit(-1);
		}
		printf("TILEIMAGE CARGADA\n");
		if (trans != "") {
			// Hacemos que no se vea el color definido en trans, formato hex ejm: #FF00FF
			string_tmp = "";
			i=0;
			for (it= trans.begin(); it != trans.end(); it++)
			{
			  if ((*it) == '#') continue;

			  string_tmp = string_tmp + (*it);
			  i++;
			  switch (i) {
				  case 2:
					  R = hex2dec(string_tmp);
					  string_tmp = "";
					  break;
				  case 4:
					  G = hex2dec(string_tmp);
					  string_tmp = "";
					  break;
				  case 6:
					  B = hex2dec(string_tmp);
					  string_tmp = "";
					  break;
				  default:
					  break;
			  }
			}
			al_convert_mask_to_alpha(bmp, al_map_rgb(R,G,B));
		}
	}
}

unsigned long TileImage::hex2dec(std::string hex)
{
    unsigned long result = 0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            result += (hex[i]-48)*pow(16,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            result += (hex[i]-55)*pow(16,hex.length( )-i-1);
        } else if (hex[i]>=97 && hex[i]<=102) {
            result += (hex[i]-87)*pow(16,hex.length()-i-1);
        }
    }
    return result;
}

