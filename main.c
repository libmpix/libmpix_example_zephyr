#include <string.h>

#include <mpix/image.h>

#define APP_WIDTH 32
#define APP_HEIGHT 32
#define APP_FOURCC MPIX_FMT_RGB24

uint8_t buf_in[APP_HEIGHT * APP_WIDTH * 3];
uint8_t buf_out[APP_HEIGHT * APP_WIDTH * 3];

static void app_generate_test_data(void)
{
	for (int h = 0; h < APP_HEIGHT; h++) {
		for (int w = 0; w < APP_WIDTH; w++) {
			uint8_t *pixel = &buf_in[h * APP_WIDTH * 3 + w * 3];

			pixel[0] = w * 5;
			pixel[1] = h * 5;
			pixel[2] = 0xff;
		}
	}
}

int main(void)
{
	struct mpix_image img;

	app_generate_test_data();

	mpix_image_from_buf(&img, buf_in, sizeof(buf_in), APP_WIDTH, APP_HEIGHT, APP_FOURCC);
	mpix_image_print_truecolor(&img);
	mpix_image_convert(&img, MPIX_FMT_YUYV);
	mpix_image_convert(&img, MPIX_FMT_RGB24);
	mpix_image_to_buf(&img, buf_out, sizeof(buf_out));

	if (img.err != 0) {
		printf("Oops an error occured: %s!\n", strerror(-img.err));
		return img.err;
	}

	mpix_image_print_truecolor(&img);

	return 0;
}
