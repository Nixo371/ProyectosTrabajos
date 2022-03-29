#include "MVP.h"


/*
SPORT 0 = BASKETBALL
SPORT 1 = HANDBALL

POSITION 0 = GUARD / GOALKEEPER
POSITION 1 = FORWARD / FIELDPLAYER
POSITION 2 = CENTER

CATEGORY 0 = SCORED POINT / INITIAL RATING POINTS
CATEGORY 1 = REBOUND / GOAL MADE
CATEGORY 2 = ASSIST / GOAL RECEIVED
*/

char	*calculate_points(char	**stats, char *sport)
{
	int basketball[3][3] = {
		{2, 3, 1},
		{2, 2, 2},
		{2, 1, 3}
	};
	int	handball[2][2] = {
		{5, -2},
		{1, -1}
	};
	int		points;
	int		position;
	int		category;
	points = ft_atoi(stats[9]);
	
	if (*stats[4] == 'G')
		position = 0;
	else if (*stats[4] == 'F')
		position = 1;
	else if (*stats[4] == 'C')
		position = 2;
	else
		return (NULL);

	category = 5;

	if (*sport == 'B') //BASKETBALL
	{
		while(stats[category])
		{
			points += (basketball[position][category - 5] * ft_atoi(stats[category]));
			category++;
		}
	}
	else //HANDBALL
	{
		while(stats[category])
		{
			points += (handball[position][category - 5] * ft_atoi(stats[category]));
			category++;
		}
		if (position == 0)
			points += 50;
		else if (position == 1)
			points += 20;
	}
	return (ft_itoa(points));
	

}

void	copy_dpointer(char	**dest, char **src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (src[i][j])
		{
			dest[i][j] = src[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

int	checkplayer(char ***standings, char **stats)
{
	int	i = 0;

	if (standings == NULL)
		return (-1);
	while (standings[i])
	{
		if (standings[i][1] == stats[1])
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	next_line = ft_line(buffer);
	buffer = ft_overflow(buffer);
	return (next_line);
}

int	find_highest_points(char	***standings)
{
	int i;

	i = 0;
	if (standings)
		i++;
	return (i);
}

char	*find_MVP(int	fd)
{
	char	***standings = NULL;
	char	*player = NULL;
	char	**stats = NULL;
	char	*sport;
	int		i = 0;


	sport = get_next_line(fd);
	standings = malloc(100 * sizeof(char **));
	do
	{
		player = get_next_line(fd);
		if (player)
		{
			stats = ft_split(player, ';');
			if (checkplayer(standings, stats) != -1)
			{
				standings[checkplayer(standings, stats)][9] = calculate_points(stats, sport);
			}
			else
			{
				stats[9] = "0";
				standings[i] = stats;
				standings[i][9] = calculate_points(stats, sport);
				i++;
			}
			// if(standings[i - 1])
			// 	printf("%s has %s points\n", standings[i - 1][1], standings[i - 1][9]);
		}
	}
	while (player);
	i = find_highest_points(standings);
	return (standings[i][0]);
}

int main()
{
	int		fd;

	fd = open("handball.txt", O_RDONLY);
	printf("The MVP is: %s\n", find_MVP(fd));
}

/*
	char	***standings = NULL;
	char	*player = NULL;
	char	**stats = NULL;
	char	*sport;
	int		fd;
	int		i = 0;
	//int		j = 0;

	fd = open("test.txt", O_RDONLY);

	sport = get_next_line(fd);

	do
	{
		player = get_next_line(fd);
		if (player)
		{
			stats = ft_split(player, ';');
			if (checkplayer(standings, stats) != -1)
			{
				standings[checkplayer(standings, stats)][9] = calculate_points(stats, sport);
			}
			else if (standings == NULL)
			{
				stats[9] = "0";
				printf("here0\n");
				copy_dpointer(standings[i], stats);
				printf("here1\n");
				standings[i][9] = calculate_points(stats, sport);
				printf("here2\n");
				i++;
			}
		}
	}
	while (player);
*/

	