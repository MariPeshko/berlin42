void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

  if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
  // int offset = (y * line_length + x * (bits_per_pixel / 8));
	{
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
  }
}