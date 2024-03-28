SELECT DISTINCT count(title) FROM movies
WHERE id in (SELECT movie_id FROM ratings WHERE rating = 10.0)
