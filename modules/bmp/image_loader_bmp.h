/*************************************************************************/
/*  image_loader_bmp.h                                                   */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2018 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2018 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef IMAGE_LOADER_BMP_H
#define IMAGE_LOADER_BMP_H

#include "core/io/image_loader.h"

class ImageLoaderBMP : public ImageFormatLoader {
protected:
	static const unsigned BITMAP_SIGNATURE = 0x4d42;

	struct bmp_header_s {
		struct bmp_file_header_s {
			uint16_t bmp_signature;
			uint32_t bmp_file_size;
			uint32_t bmp_file_padding;
			uint32_t bmp_file_offset;
		} bmp_file_header;

		struct bmp_info_header_s {
			uint32_t bmp_header_size;
			uint32_t bmp_width;
			uint32_t bmp_height;
			uint16_t bmp_planes;
			uint16_t bmp_bit_count;
			uint32_t bmp_compression;
			uint32_t bmp_size_image;
			uint32_t bmp_pixels_per_meter_x;
			uint32_t bmp_pixels_per_meter_y;
			uint32_t bmp_colors_used;
			uint32_t bmp_important_colors;
			uint32_t bmp_red_mask;
			uint32_t bmp_green_mask;
			uint32_t bmp_blue_mask;
			uint32_t bmp_alpha_mask;
			uint32_t bmp_cs_type;
			uint32_t bmp_endpoints[9];
			uint32_t bmp_gamma_red;
			uint32_t bmp_gamma_green;
			uint32_t bmp_gamma_blue;
		} bmp_info_header;
	};

	static Error convert_to_image(Ref<Image> p_image,
			const uint8_t *p_buffer,
			const uint8_t *p_color_buffer,
			const bmp_header_s &p_header);

public:
	virtual Error load_image(Ref<Image> p_image, FileAccess *f,
			bool p_force_linear, float p_scale);
	virtual void get_recognized_extensions(List<String> *p_extensions) const;
	ImageLoaderBMP();
};

#endif // IMAGE_LOADER_BMP_H