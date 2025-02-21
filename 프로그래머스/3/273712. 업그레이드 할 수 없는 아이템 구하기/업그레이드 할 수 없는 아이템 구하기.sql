# -- 코드를 작성해주세요
# WITH V AS (SELECT DISTINCT I.ITEM_ID
# FROM ITEM_INFO I
# JOIN ITEM_TREE T ON I.ITEM_ID = T.PARENT_ITEM_ID)

# SELECT ITEM_ID, ITEM_NAME, RARITY
# FROM ITEM_INFO
# WHERE ITEM_ID NOT IN (SELECT * FROM V)
# ORDER BY ITEM_ID DESC






# WITH V AS (
#     SELECT I.ITEM_ID
#     FROM ITEM_INFO I
#     JOIN ITEM_TREE T
#     ON I.ITEM_ID = T.PARENT_ITEM_ID
# )


# SELECT I.ITEM_ID, ITEM_NAME, RARITY
# FROM ITEM_INFO I
# WHERE I.ITEM_ID NOT IN (SELECT * FROM V)
# ORDER BY I.ITEM_ID DESC








SELECT I.ITEM_ID AS ITEM_ID, I.ITEM_NAME AS ITEM_NAME, RARITY
FROM ITEM_INFO I
LEFT JOIN ITEM_TREE T ON I.ITEM_ID = T.PARENT_ITEM_ID
WHERE T.PARENT_ITEM_ID IS NULL
ORDER BY I.ITEM_ID DESC;









