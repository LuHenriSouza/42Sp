#include "fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rectangle(t_data *img)
{
	int x;
	int y;
	int color = 0x00FF0000; // Vermelho

	// Desenhando um retângulo de 100x100 pixels
	for (y = 50; y < 150; y++)
	{
		for (x = 50; x < 150; x++)
		{
			my_mlx_pixel_put(img, x, y, color);
		}
	}
}

void	draw_line(t_data *img)
{
	int x;
	int y;
	int color = 0x0000FF00; // Verde

	// Desenhando uma linha diagonal de (0,0) até (1920, 1080)
	for (x = 0, y = 0; x < 1920 && y < 1080; x++, y++)
	{
		my_mlx_pixel_put(img, x, y, color);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Drawing Test");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// Desenhando um retângulo e uma linha
	draw_rectangle(&img);
	draw_line(&img);

	// Colocando a imagem na janela
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}
