#ifndef MVP_H
# define MVP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

// typedef struct
// {
// 	char	*name;
// 	char	*nick;
// 	int		points;
// } person;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*calculate_points(char	**stats, char *sport);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *player);
char	*ft_line(char *buffer);
char	*ft_overflow(char *buffer);

void	copy_dpointer(char	**dest, char **src);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *ptr);
char	*ft_itoa(int n);

#endif