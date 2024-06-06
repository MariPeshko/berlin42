typedef struct t_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct t_relement
{
	t_img			wall;

}	t_relement;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	t_relement	*assets;
}	t_mlx;
