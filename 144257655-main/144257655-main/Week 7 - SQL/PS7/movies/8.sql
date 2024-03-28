SELECT name FROM people
WHERE id in (SELECT stars.person_id
FROM stars JOIN movies ON stars.movie_id = movies.id
WHERE movies.title LIKE 'Toy Story')
