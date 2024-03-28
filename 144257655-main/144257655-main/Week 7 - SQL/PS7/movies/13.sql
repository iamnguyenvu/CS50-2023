SELECT DISTINCT p.name FROM people p
JOIN stars s ON s.person_id = p.id
JOIN movies m ON m.id = s.movie_id
WHERE m.id IN
(SELECT movies.id FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name = 'Kevin Bacon' AND people.birth = 1958)
AND p.name != 'Kevin Bacon'

