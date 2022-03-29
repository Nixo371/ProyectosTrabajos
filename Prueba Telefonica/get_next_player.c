#include "MVP.h"

char	*ft_read(int fd, char *player)
{
	char	*aux;
	int		read_return;

	aux = malloc(2 * sizeof(char));
	if (aux == NULL)
		return (0);
	read_return = -1;
	while (!ft_strchr(player, '\n') && read_return != 0)
	{
		read_return = read(fd, aux, 1);
		if (read_return == -1)
		{
			free(aux);
			return (NULL);
		}
		aux[read_return] = '\0';
		player = ft_strjoin(player, aux);
	}
	free(aux);
	return (player);
}

char	*ft_line(char *buffer)
{
	char	*aux;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	aux = malloc((i + 2) * sizeof(char));
	if (aux == NULL)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		aux[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		aux[i] = buffer[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*ft_overflow(char *buffer)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	aux = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (aux == NULL)
		return (NULL);
	i++;
	while (buffer[i])
	{
		aux[j++] = buffer[i++];
	}
	aux[j] = '\0';
	free(buffer);
	return (aux);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return (&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	j = i;
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}
