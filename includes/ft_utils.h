/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:46:56 by drenassi          #+#    #+#             */
/*   Updated: 2023/11/22 20:59:57 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_C
# define FT_UTILS_C


/*********************************** UTILS ************************************/
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t n, size_t size);
void	ft_print_error(const char *str);
void	ft_free_array(char **array);

/******************************* GET NEXT LINE ********************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*gnl_strchr(char const *s, int c);
size_t	gnl_strlen(char const *s);
char	*gnl_strdup(char const *src);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

/*********************************** ERRORS ***********************************/
int		ft_args_error(int ac);
int		ft_check_rect(char **map);
int		ft_check_forbidden_char(char **map);
int		ft_check_walls(char **map);
int		ft_check_map(char *file);
int		ft_replace_map(t_map map, int res);
int		ft_check_exit_reachable(t_map map, int x, int y);
int		ft_check_items_reachable(t_map map, int x, int y, t_items item);
int		ft_check_completable(t_map map, int x, int y);

/************************************ MAPS ************************************/
int		ft_get_map_height(char *file);
int		ft_get_items_count(t_map map);
void	ft_set_items_pos(t_map *map);
char	**ft_get_map(char *file);
void	ft_init_map(t_map *map, char *file);
void	ft_free_map(t_map *map);

/*********************************** DEBUG ************************************/
void	ft_print_map(t_map map);

#endif