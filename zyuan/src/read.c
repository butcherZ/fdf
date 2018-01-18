#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdio.h>


char		**my_get_line(int fd, char **line)
{
	//		int 	**array;
	char	**str;
	while (get_next_line(fd, line) == 1)
	{
		//printf("%s\n", *line);
		str = ft_strsplit(*line, ' ');
		printf("%s\n", str[0]);
		//free(str);
	}

	return (str);
}

void	print_tab(char **str)
{
		if (str)
		{
			int i = 0;

			while (*(str + i))
			{
				printf("%s", *(str + i));
				free(*(str + i));
				i++;
			}
			printf("\n");
			free(str);
		}
}

int main(int argc, char *argv[])
{
	int fd;
	char *line;

	fd = 0;
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
/*		print_tab(*/my_get_line(fd, &line)/*)*/;
//		printf("%s\n", my_get_line(fd, &line)[0]);
	free(line);

	close(fd);
	return (0);
}
