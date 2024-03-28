SELECT DISTINCT name FROM people
WHERE id in (SELECT directors.person_id
FROM ratings JOIN movies ON movies.id = ratings.movie_id
JOIN directors ON directors.movie_id = movies.id
WHERE ratings.rating >= 9.0)
