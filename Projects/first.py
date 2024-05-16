#importing necessary libraries
import csv
import googleapiclient.discovery
from googletrans import Translator
import emoji
import pandas as pd

#setting up API service
api_service_name = "youtube"
api_version = "v3"
DEVELOPER_KEY = "AIzaSyCT5ZqsK4tlX9PBrZ5SWKzekux2RsAOHFs"
youtube = googleapiclient.discovery.build(
    api_service_name, api_version, developerKey=DEVELOPER_KEY)
def get_comments(video_id, max_comments):
    comments = []
    response = youtube.commentThreads().list(
        part="snippet",
        videoId='73_1biulkYk',
        maxResults=100  # API allows a maximum of 100 results per request
    ).execute()

    while response and len(comments) < max_comments:
        for item in response["items"]:
            comment = item["snippet"]["topLevelComment"]["snippet"]["textDisplay"]
            comments.append(comment)
            if len(comments) >= max_comments:
                break

        # Check for nextPageToken
        if 'nextPageToken' in response:
            response = youtube.commentThreads().list(
                part="snippet",
                videoId=video_id,
                maxResults=100,
                pageToken=response['nextPageToken']
            ).execute()
        else:
            break

    return comments

# Extract comments
video_id = "ea94nqoxnVQ"
max_comments = 100000  # Desired number of comments
comments = get_comments(video_id, max_comments)

# Save comments to a CSV file
with open('youtube_comments.csv', 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    writer.writerow(["Comment"])
    for comment in comments:
        writer.writerow([comment])
print(f"Number of comments extracted: {len(comments)}")

print(f"Number of comments extracted: {len(comments)}")
#converting to file
csv_file="translated_comments.csv"

with open(csv_file,mode='w',newline='',encoding='utf-8')as file:
    writer= csv.writer(file)
    for comment in comments:
      writer.writerow([comment])
df=pd.read_csv("translated_comments.csv")
