SELECT name FROM songs
WHERE artist_id in (SELECT id FROM artists WHERE name = 'Post Malone')
