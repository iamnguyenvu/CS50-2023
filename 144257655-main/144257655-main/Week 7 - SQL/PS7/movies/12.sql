SELECT title FROM ratings r JOIN movies m On r.movie_id = m.id
JOIN stars s ON m.id = s.movie_id JOIN people p ON s.person_id = p.id
WHERE p.name = 'Bradley Cooper'
AND title IN
(SELECT title FROM ratings r JOIN movies m On r.movie_id = m.id
JOIN stars s ON m.id = s.movie_id JOIN people p ON s.person_id = p.id
WHERE p.name = 'Jennifer Lawrence')
